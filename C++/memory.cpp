#include<iostream>

class MemoryPool {
    private:
        void* poolMemory;
        size_t poolSize;
        size_t used;
        bool* allocationMap;
    
    public:
        // Create a memory pool of fixed size
        MemoryPool(size_t size) : poolSize(size), used(0) {
            // Allocate the pool memory
            poolMemory = operator new(size);
            
            // Create allocation tracking map
            allocationMap = new bool[size / 64](); // Assuming minimum allocation of 64 bytes
        }
        
        // Allocate memory from the pool
        void* allocate(size_t size) {
            // Align size to multiples of 8 bytes
            size = (size + 7) & ~7;
            
            // Find available block
            for (size_t i = 0; i < poolSize - size; i += 8) {
                if (isBlockFree(i, size)) {
                    markBlockUsed(i, size);
                    used += size;
                    // Return pointer to allocated memory
                    return static_cast<char*>(poolMemory) + i;
                }
            }
            
            // Out of memory in the pool
            throw std::bad_alloc();
        }
        
        // Free memory back to the pool
        void deallocate(void* ptr, size_t size) {
            // Align size to multiples of 8 bytes
            size = (size + 7) & ~7;
            
            // Calculate the offset of this pointer in the pool
            size_t offset = static_cast<char*>(ptr) - static_cast<char*>(poolMemory);
            
            // Mark this block as free
            markBlockFree(offset, size);
            used -= size;
        }
        
        // Memory pool destructor
        ~MemoryPool() {
            operator delete(poolMemory);
            delete[] allocationMap;
        }
        
    private:
        // Helper methods to track allocations (simplified)
        bool isBlockFree(size_t offset, size_t size) {
            // Implementation details omitted for brevity
            return true; // Placeholder
        }
        
        void markBlockUsed(size_t offset, size_t size) {
            // Implementation details omitted for brevity
        }
        
        void markBlockFree(size_t offset, size_t size) {
            // Implementation details omitted for brevity
        }
    };
    
    // Example usage
void useMemoryPool() {
    // Create a 4KB memory pool
    MemoryPool pool(4096);
    
    // Allocate objects from the pool
    MyClass* obj1 = static_cast<MyClass*>(pool.allocate(sizeof(MyClass)));
    
    // Construct the object using placement new
    new(obj1) MyClass();
    
    // Use the object...
    
    // Destroy the object and deallocate memory
    obj1->~MyClass();
    pool.deallocate(obj1, sizeof(MyClass));
}



int main()
{
    MemoryPool pool(4096);
        
    // Allocate objects from the pool
    MyClass* obj1 = static_cast<MyClass*>(pool.allocate(sizeof(MyClass)));
    
    // Construct the object using placement new
    new(obj1) MyClass();
    
    // Use the object...
    
    // Destroy the object and deallocate memory
    obj1->~MyClass();
    pool.deallocate(obj1, sizeof(MyClass));
}