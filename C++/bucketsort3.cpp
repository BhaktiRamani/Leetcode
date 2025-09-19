#include<iostream>
#include <vector>
#include <algorithm>
#include<set>
#include<thread>
#include<mutex>
#include<memory>
using namespace std;

typedef struct{
    vector<set<int>> result;
    vector<unique_ptr<mutex>> guard;
}buckets; 

int right_most_number(int num)
{
    if(num > 9)
    {
        int right_num = 10;
        while(right_num > 9)
        {
            right_num = num / 10;  
            num = num / 10;
        }
        // cout << right_num << endl;
        return right_num;
    }
    else
    {
        return num;
    }
}

unsigned int hash2(unsigned int num, buckets* main_bucket)
{
    return num;
}

bool hash_table_insert(int index, buckets* main_bucket, int num)
{
    cout << "hash table insert" << endl;

    if (index >= main_bucket->result.size()) {
        main_bucket->result.resize(10);  // grow outer vector
    }
    
    main_bucket->result[index].insert(num);
    return true;
}

void print_hash_table(const buckets& main_bucket)
{
    cout << "\n=== Hash Table ===" << endl;

    for (size_t i = 0; i < main_bucket.result.size(); i++)
    {
        cout << "Bucket " << i << ": ";
        for(auto val : main_bucket.result[i])
        {
            cout << val << " , ";
        }
        cout << endl;
    }

    cout << "==================\n" << endl;
}

set<int> merge_buckets(buckets &bucket)
{
    set<int>list; 

    for(int i = 0; i < bucket.result.size(); i++)
    {
        for(auto val : bucket.result[i])
        {
            list.insert(val);
        }
    }

    cout << "Sorted List : [";
    for(auto val : list)
    {
        cout << val << " , ";
    }
    cout << "]" << endl;

    return list;
}

void bucketSort2(int thread_id, vector<int>& vec, int no_of_threads, buckets &bucket)
{
    // cout << "Bucket Sort" << endl;
    for (int i = thread_id; i < vec.size(); i += no_of_threads) {
        cout << "Thread " << thread_id << " got element " << vec[i] << endl;

        int index = right_most_number(vec[i]);
        // cout << "Index : " << index << " val : " << vec[i] << endl;

        bucket.guard[index]->lock();
        hash_table_insert(index, &bucket, vec[i]);
        bucket.guard[index]->unlock();
    }
    cout << endl;
}

int main()
{
    buckets main_bucket;

    vector<int> vec = {5,55,54,53,52};
    int no_of_threads = 3;
    int num_buckets = 10;
    
    // Resize the result vector
    main_bucket.result.resize(num_buckets);
    
    // Initialize mutexes using unique_ptr
    main_bucket.guard.reserve(num_buckets);
    for(int i = 0; i < num_buckets; i++) {
        main_bucket.guard.push_back(make_unique<mutex>());
    }

    // store all threads
    vector<thread> threads;

    // create threads
    for (int t = 0; t < no_of_threads; t++) {
        threads.emplace_back(
            bucketSort2,
            t,                    // pass by value (ok)
            std::ref(vec),        // wrap vector reference
            no_of_threads,        // pass by value (ok)
            std::ref(main_bucket) // wrap bucket reference
        );
    }

    // wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }

    print_hash_table(main_bucket);

    // merge all the buckets 
    merge_buckets(main_bucket);
    
    return 0;
}