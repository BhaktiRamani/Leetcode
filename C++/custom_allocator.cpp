#include <iostream>
#include <vector>

using namespace std;

template <typename T>

// we are using :: to reference to the global variable new and delete
class MyAllocator{
    public:
    using value_type = T;

    // first we will allocate memory using operator new but it gives void pointer and we need to return
    // pointer of T(any) type
    T* allocate(size_t size)
    {
        // casting it to T type
        T* ptr = static_cast<T*>(::operator new(size * sizeof(T)));
        return ptr;
    }

    // now delete the allocated memory
    void deallocate(T* p, size_t) noexcept {
        ::operator delete(p);
    }
    
};


int main() {
    // Vector using our custom allocator
    vector<int, MyAllocator<int>> vec;

    // Insert some elements
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }

    // Print elements
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
