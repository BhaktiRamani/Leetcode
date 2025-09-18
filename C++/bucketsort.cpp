#include<iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

#define MAX_NUM 256
#define TABLE_SIZE 10

typedef struct{
    vector<vector<int>> vec;
    
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

    if (index >= main_bucket->vec.size()) {
        main_bucket->vec.resize(10);  // grow outer vector
    }
    // main_bucket->vec[2][0] = 22;
    
    // cout << main_bucket->vec[2][0] << endl;
    main_bucket->vec[index].push_back(num);

    cout << "value " << main_bucket->vec[index].back() << endl;
    return true;
}

void swaping( buckets *main_bucket)
{
    cout << "Swap " << endl;
    for (int i = 0; i < main_bucket->vec.size(); i++) {
        for (int j = 0; j + 1 < main_bucket->vec[i].size(); j++) {
            if (main_bucket->vec[i][j] > main_bucket->vec[i][j+1]) {
                cout << "swap condition true: "
                    << main_bucket->vec[i][j] << ", "
                    << main_bucket->vec[i][j+1] << endl;
                swap(main_bucket->vec[i][j], main_bucket->vec[i][j+1]);
            }
        }
    }
    cout << endl;

}

void print_hash_table(const buckets& main_bucket)
{
    cout << "\n=== Hash Table ===" << endl;

    for (size_t i = 0; i < main_bucket.vec.size(); i++)
    {
        cout << "Bucket " << i << ": ";

        if (main_bucket.vec[i].empty()) {
            cout << "(empty)";
        } else {
            for (size_t j = 0; j < main_bucket.vec[i].size(); j++) {
                cout << main_bucket.vec[i][j];
                if (j + 1 < main_bucket.vec[i].size()) cout << ", ";
            }
        }
        cout << endl;
    }

    cout << "==================\n" << endl;
}


// ```
// function bucketSort(input_array, k) :
//   buckets[] : array of k empty sorted lists
//   mins[] : array of k+1 minimum values for each list in buckets
//   // bucket[m] holds (sorted) values from mins[m] to mins[m+1], so
//   // mins[0]=0; mins[k]=INT_MAX;
//   for i = 0 to length(input_array) do
//     for j = 0 to k do
// 		if(input_array[i]<mins[j]) // find bucket to insert 
// 			insert input_array[i] into buckets[j-1]
//   return the concatenation of buckets[0], ...., buckets[k-1]
// 

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

void hash_bucket_insert(vector<int> input_arr, elements *data)
{
    for(int val : input_arr)
    {
        for(int j = 0; j < data->number_of_buckets; j++)
        {
            if(val >= data->limits[j] && val < data->limits[j+1])
            {
                data->buckets[j].insert(val);
                break;  // once inserted, stop inner loop
            }
        }
    }
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

void bucketSort(vector<int> input_arr, int k)
{

    elements data; 
    data.number_of_buckets = k;
    data.buckets.resize(k);      

    hash_func(&data, input_arr);      // compute limits
    hash_bucket_insert(input_arr, &data);  // insert values into buckets
    print_hash_buckets(&data);             // print bucket contents
    result(&data);                         // print sorted result

    // int number_of_buckets = k;
    // vector<set<int>> buckets(number_of_buckets);

    // vector<int> limits;

    // int min = *std::min_element(input_arr.begin(), input_arr.end());
    // int max = *std::max_element(input_arr.begin(), input_arr.end());

    // cout << "Min element : " << min << " Max element : " << max << endl;
    // cout << "Number of buckets : " << number_of_buckets << endl;
    // int width = (max - min )/ number_of_buckets; 

    // cout << "Width : " << width << endl;

    // for(int i = 0; i < number_of_buckets ; i++)
    // {
    //     limits.push_back(min);
    //     min = min + width;
    // }
    // limits.push_back(max + 1);
    // for(int i = 0; i < number_of_buckets + 1; i++)
    // {
    //     cout << limits[i] << endl;
    // }


    // for(int i = 0; i < input_arr.size(); i++)
    // {
    //     for(int j = 0; j < limits.size(); j++)
    //     {
    //         if(input_arr[i] >= limits[j] && input_arr[i] <limits[j+1])
    //         {
    //             cout << "Bucket no : " << j << " Val : " << input_arr[i] << endl;
    //             buckets[j].insert(input_arr[i]);
    //         }
    //     }
    // }

    // cout << "============ Buckets ==========" << endl;
    // for (int i = 0; i < buckets.size(); i++) {
    //     cout << "bucket " << i << " : ";
    //     bool first = true;
    //     for (const int& element : buckets[i]) {
    //         if (!first) cout << " ,";
    //         cout << element;
    //         first = false;
    //     }
    //     cout << endl;
    // }
    // cout << "==================\n" << endl;

    // set<int> result; 

    // for(int i = 0; i < number_of_buckets; i++)
    // {
    //     result.insert(buckets[i].begin(), buckets[i].end());
    // }

    // for(auto i : result)
    // {
    //     cout << i << endl;
    // }
    return; 
}


int main()
{
    int arr[5];
    int nums[5] = {10,2,3,1,4};

    // vector<int> vec = {1,2,4,6,7,21,23,45,10,91};
    vector<int> vec = {21,23,45,10,91, 4,6,7, 2, 1};
    // buckets main_bucket;
    

    // for(int i = 0; i< vec.size(); i++)
    // {
        
    //     // int index = right_most_number(vec[i]);
    //     cout << "Index : " << index << " Vec : " << vec[i] << endl;
        
    //     // inser in hash table
    //     hash_table_insert(index, &main_bucket, vec[i]);

    //     cout << endl;

    // }

    // print_hash_table(main_bucket);

    // swaping(&main_bucket);

    // print_hash_table(main_bucket);


    bucketSort(vec, 5);


 

}