#include <iostream>
#include <pthread.h>
#include <vector>
#include <chrono>
using namespace std::chrono;

struct SumArgs {
    int* arr;
    int lo;
    int hi;
    int ans;
    int depth;  // track recursion depth
};

// Recursive threaded sum function
void* threadedSum(void* arg) {
    SumArgs* args = (SumArgs*) arg;
    int lo = args->lo, hi = args->hi;

    // indentation for tree structure
    std::string indent(args->depth * 4, ' ');

    if (hi - lo == 1) {   // base case: single element
        args->ans = args->arr[lo];
        std::cout << indent << "Leaf [" << lo << "] = " << args->ans << std::endl;
    } else {
        int mid = (lo + hi) / 2;

        // Left and right subproblems
        SumArgs leftArgs{args->arr, lo, mid, 0, args->depth + 1};
        SumArgs rightArgs{args->arr, mid, hi, 0, args->depth + 1};

        pthread_t leftThread, rightThread;

        std::cout << indent << "Fork: range [" << lo << "," << hi << ")"
                  << " → [" << lo << "," << mid << ") and [" << mid << "," << hi << ")\n";

        // Fork step
        pthread_create(&leftThread, nullptr, threadedSum, &leftArgs);
        pthread_create(&rightThread, nullptr, threadedSum, &rightArgs);

        // Join step
        pthread_join(leftThread, nullptr);
        pthread_join(rightThread, nullptr);

        args->ans = leftArgs.ans + rightArgs.ans;

        std::cout << indent << "Join: range [" << lo << "," << hi << ")"
                  << " → sum = " << leftArgs.ans << " + " << rightArgs.ans
                  << " = " << args->ans << std::endl;
    }
    return nullptr;
}
int run(const std::vector<int>& arr, int lo, int hi, int depth = 0) {
    std::string indent(depth * 4, ' '); // 4 spaces per level

    std::cout << indent << "Entering: lo=" << lo << ", hi=" << hi << std::endl;

    if (hi - lo == 1) {  
        // Base case: one element
        std::cout << indent << "Base case at index " << lo 
                  << " value=" << arr[lo] << std::endl;
        return arr[lo];
    } else {
        int mid = (lo + hi) / 2;
        std::cout << indent << "Splitting at mid=" << mid << std::endl;

        // Recursive calls
        std::cout << indent << "Left recursion:" << std::endl;
        int left = run(arr, lo, mid, depth + 1);

        std::cout << indent << "Right recursion:" << std::endl;
        int right = run(arr, mid, hi, depth + 1);

        int ans = left + right;
        std::cout << indent << "Merging: lo=" << lo << ", hi=" << hi 
                  << " left=" << left << " right=" << right 
                  << " sum=" << ans << std::endl;
        return ans;
    }
}

int sum(const std::vector<int>& arr) {
    return run(arr, 0, arr.size());
}
int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SumArgs args{arr.data(), 0, (int)arr.size(), 0, 0};

    auto start = high_resolution_clock::now();

    pthread_t root;
    pthread_create(&root, nullptr, threadedSum, &args);
    pthread_join(root, nullptr);
    int result = sum(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std :: cout << "Duration : " <<  duration.count() << std :: endl;
    std::cout << "Final sum = " << args.ans << std::endl;
    std::cout << "Final sum = " << result << std::endl;
    return 0;
}



// #include <iostream>
// #include <vector>
// #include <string>



// int main() {
//     std::vector<int> arr = {1, 2, 3, 4, 5};
//     int result = sum(arr);
//     std::cout << "Final Sum = " << result << std::endl;
//     return 0;
// }
