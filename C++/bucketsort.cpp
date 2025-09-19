#include<iostream>
#include <vector>
#include <algorithm>
#include<set>
#include<thread>
using namespace std;

#define MAX_NUM 256
#define TABLE_SIZE 10

typedef struct{
    vector<set<int>> result;
    // vector<std::mutex> bucket_guard;
}buckets; 


int right_most_number(int num)
{
    if(num > 9)
    {
        int right_num = 10;
        while(right_num > 9)
        {
        
            right_num = num/10;
            num = right_num;
        }
        cout << right_num << endl;
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

void print_hash_table(vector<int> vec)
{
    printf("Printing hash table\n");
    for(int i = 0; i<vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    printf("End of hash table\n");
    return;
}

bool hash_table_insert(int index, buckets* main_bucket, int num)
{
    cout << "hash table insert" << endl;

    if (index >= main_bucket->result.size()) {
        main_bucket->result.resize(10);  // grow outer vector
    }
    // main_bucket->vec[2][0] = 22;
    
    // cout << main_bucket->vec[2][0] << endl;
    main_bucket->result[index].insert(num);

    // cout << "value " << main_bucket->result[index].back() << endl;
    return true;
}

void swaping( buckets *main_bucket)
{
    // cout << "Swap " << endl;
    // for (int i = 0; i < main_bucket->result.size(); i++) {
    //     for (int j = 0; j + 1 < main_bucket->result[i].size(); j++) {
    //         if (main_bucket->result[i][j] > main_bucket->result[i][j+1]) {
    //             cout << "swap condition true: "
    //                 << main_bucket->result[i][j] << ", "
    //                 << main_bucket->result[i][j+1] << endl;
    //             swap(main_bucket->result[i][j], main_bucket->result[i][j+1]);
    //         }
    //     }
    // }
    cout << endl;

}

void print_hash_table(const buckets& main_bucket)
{
    cout << "\n=== Hash Table ===" << endl;

    for (size_t i = 0; i < main_bucket.result.size(); i++)
    {
        cout << "Bucket " << i << ": ";

        // if (main_bucket.result[i].empty()) {
        //     cout << "(empty)";
        // } else {
        //     for (size_t j = 0; j < main_bucket.result[i].size(); j++) {
        //         cout << main_bucket.result[i](j);
        //         if (j + 1 < main_bucket.result[i].size()) cout << ", ";
        //     }
        // }
        for(auto val : main_bucket.result[i])
        {
            cout << val << " , ";
        }
        cout << endl;
    }

    cout << "==================\n" << endl;
}

void merge_buckets(buckets &bucket)
{
    set<int>list; 
    // list.

    // for(int i = 0; i < bucket.result.size(); i++)
    //     list.insert(list.end(), bucket.result[i].begin(), bucket.result[i].end());

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
}

void bucketSort2(int thread_id, vector<int>& vec, int no_of_threads, buckets &bucket)
{
    cout << "Bucket Sort" << endl;
    for (int i = thread_id; i < vec.size(); i += no_of_threads) {
        cout << "Thread " << thread_id 
             << " got element " << vec[i] << endl;
             int index = right_most_number(vec[i]);
             cout << "Index : " << index << " val : " << vec[i] << endl;
             hash_table_insert(index, &bucket, vec[i]);
    }
    // inser in hash table
    cout << endl;
}

typedef struct{
    vector<set<int>>buckets;
    int number_of_buckets; 
    vector<int>limits;
    set<int> result; 
}elements;

void hash_func(elements* data, vector<int> input_arr)
{
    int number_of_buckets = data -> number_of_buckets;
    
    vector<set<int>> buckets[number_of_buckets];

    vector<int> limits;

    int min = *std::min_element(input_arr.begin(), input_arr.end());
    int max = *std::max_element(input_arr.begin(), input_arr.end());

    cout << "Min element : " << min << " Max element : " << max << endl;
    cout << "Number of buckets : " << number_of_buckets << endl;
    int width = (max - min )/ number_of_buckets; 

    cout << "Width : " << width << endl;

    for(int i = 0; i < number_of_buckets; i++)
    {
        // limits.push_back(min);
        data -> limits.push_back(min);
        min = min + width;
    }
    data -> limits.push_back(max + 1);
    cout << "Limits : [ ";
    for(int i = 0; i < number_of_buckets + 1; i++)
    {
        cout << data -> limits[i] << " , ";
    }
    cout << "]" << endl;;

}

void hash_bucket_insert(vector<int> input_arr, elements *data, int no_of_threads, int num)
{
    
    // for(int val : input_arr)
    // {
        for(int j = 0; j < data->number_of_buckets; j++)
        {
            if(num >= data->limits[j] && num < data->limits[j+1])
            {
                data->buckets[j].insert(num);
                break;  // once inserted, stop inner loop
            }
        }
    // }
}

void print_hash_buckets(elements *data)
{
    cout << "============ Buckets ==========" << endl;
    for (int i = 0; i < data -> buckets.size(); i++) {
        cout << "bucket " << i << " : ";
        bool first = true;
        for (const int& element : data -> buckets[i]) {
            if (!first) cout << " ,";
            cout << element;
            first = false;
        }
        cout << endl;
    }
    cout << "==================\n" << endl;

}

void result(elements *data)
{
    data->result.clear();
    for(int i = 0; i < data->number_of_buckets; i++)
    {
        data->result.insert(data->buckets[i].begin(), data->buckets[i].end());
    }

    cout << "Sorted result:" << endl;
    for(auto val : data->result)
    {
        cout << val << " ";
    }
    cout << endl;
}

void bucketSort(vector<int> input_arr, int k, int no_of_threads)
{

    elements data; 
    data.number_of_buckets = k;
    data.buckets.resize(k);      

    hash_func(&data, input_arr);      // compute limits

    //can be parallized
    // create no_of_threads

    // give elements sequentially to different threads


    for(int i = 0; i < input_arr.size(); i++)
    {
        hash_bucket_insert(input_arr, &data, no_of_threads, input_arr[i]);  // insert values into buckets
    }


    print_hash_buckets(&data);             // print bucket contents


    result(&data);                         // print sorted result

    cout << endl;
    return; 
}



int main()
{


    // vector<int> vec = {1,2,4,6,7,21,23,45,10,91};

    buckets main_bucket;

    vector<int> vec = {21,23,45,10,91,4,6,7,2,1};
    int no_of_threads = 3;

    // store all threads
    vector<thread> threads;

    // create threads
    for (int t = 0; t < no_of_threads; t++) {
        
        threads.emplace_back(bucketSort2, t, ref(vec), no_of_threads, main_bucket);
    }

    // wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }


    print_hash_table(main_bucket);

    // merge all the buckets 
    merge_buckets(main_bucket);





    // bucketSort(vec, 3, 3);


 

}