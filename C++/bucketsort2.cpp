#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <pthread.h>

using namespace std;

// ----------------- Elements Struct -----------------
struct elements {
    vector<set<int>> buckets;         // each bucket is a sorted set
    int number_of_buckets;
    vector<int> limits;               // bucket boundaries
    set<int> result;                  // final sorted set
    vector<pthread_mutex_t> bucket_mutexes; // one mutex per bucket
};

// ----------------- Thread Args -----------------
struct ThreadArgs {
    elements *data;
    vector<int> *input_arr;
    int start_idx;
    int end_idx;
    int thread_id;   // ID for monitoring
};

// ----------------- Thread Function -----------------
void* insert_thread(void* arg) {
    ThreadArgs* args = (ThreadArgs*)arg;
    elements* data = args->data;
    vector<int>& input_arr = *(args->input_arr);

    for(int i = args->start_idx; i < args->end_idx; i++) {
        int val = input_arr[i];

        // find correct bucket
        for(int j = 0; j < data->number_of_buckets; j++) {
            if(val >= data->limits[j] && val < data->limits[j+1]) {
                pthread_mutex_lock(&data->bucket_mutexes[j]);
                data->buckets[j].insert(val);

                // ---- Monitoring print statement ----
                cout << "[Thread " << args->thread_id << "] Inserted " 
                     << val << " into bucket " << j << endl;

                pthread_mutex_unlock(&data->bucket_mutexes[j]);
                break;
            }
        }
    }
    return nullptr;
}

// ----------------- Compute Bucket Limits -----------------
void compute_limits(elements &data, const vector<int> &input_arr) {
    int min_val = *min_element(input_arr.begin(), input_arr.end());
    int max_val = *max_element(input_arr.begin(), input_arr.end());

    cout << "Min element: " << min_val << ", Max element: " << max_val << endl;

    int width = (max_val - min_val + data.number_of_buckets - 1) / data.number_of_buckets; // ceil division
    cout << "Number of buckets: " << data.number_of_buckets << ", Width: " << width << endl;

    data.limits.clear();
    for(int i = 0; i < data.number_of_buckets; i++)
        data.limits.push_back(min_val + i*width);
    data.limits.push_back(max_val + 1);

    cout << "Bucket limits: ";
    for(auto l : data.limits)
        cout << l << " ";
    cout << endl;
}

// ----------------- Print Buckets -----------------
void print_buckets(elements &data) {
    cout << "\n========== Buckets ==========" << endl;
    for(int i = 0; i < data.number_of_buckets; i++) {
        cout << "Bucket " << i << ": ";
        bool first = true;
        for(int val : data.buckets[i]) {
            if(!first) cout << ", ";
            cout << val;
            first = false;
        }
        cout << endl;
    }
    cout << "============================" << endl;
}

// ----------------- Merge Buckets into Result -----------------
void merge_buckets(elements &data) {
    data.result.clear();
    for(int i = 0; i < data.number_of_buckets; i++)
        data.result.insert(data.buckets[i].begin(), data.buckets[i].end());

    cout << "\nSorted Result: ";
    for(int val : data.result)
        cout << val << " ";
    cout << endl;
}

// ----------------- BucketSort with pthread -----------------
void bucketSort(vector<int> &input_arr, int k, int no_of_threads) {
    elements data;
    data.number_of_buckets = k;
    data.buckets.resize(k);
    data.bucket_mutexes.resize(k);
    
    // Initialize mutexes
    for(int i = 0; i < k; i++)
        pthread_mutex_init(&data.bucket_mutexes[i], nullptr);

    compute_limits(data, input_arr);

    int N = input_arr.size();
    int chunk_size = (N + no_of_threads - 1)/no_of_threads;

    vector<pthread_t> threads(no_of_threads);
    vector<ThreadArgs> args(no_of_threads);

    // Create threads
    for(int t = 0; t < no_of_threads; t++) {
        args[t].data = &data;
        args[t].input_arr = &input_arr;
        args[t].start_idx = t*chunk_size;
        args[t].end_idx = min((t+1)*chunk_size, N);
        args[t].thread_id = t;

        pthread_create(&threads[t], nullptr, insert_thread, &args[t]);
    }

    // Join threads
    for(int t = 0; t < no_of_threads; t++)
        pthread_join(threads[t], nullptr);

    print_buckets(data);
    merge_buckets(data);

    // Destroy mutexes
    for(int i = 0; i < k; i++)
        pthread_mutex_destroy(&data.bucket_mutexes[i]);
}

// ----------------- Main -----------------
int main() {
    vector<int> input_arr = {1, 2, 4, 6, 7, 21, 23, 45, 10, 91};
    int k = 4;              // number of buckets
    int no_of_threads = 3;  // number of threads

    bucketSort(input_arr, k, no_of_threads);
    return 0;
}
