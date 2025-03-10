class CircularBuffer:
    def __init__(self, max_len):
        self.max_len = max_len
        self.buffer = [None]*max_len
        self.write_Index = 0
        self.read_Index = 0
        self.count = 0
        
    def isFull(self):
        return self.max_len == self.count
    def isEmpty(self):
        return self.count == 0
    
    def enqueue(self, data):
        print(f"Read Index : {self.read_Index} Write Index : {self.write_Index} W_Data : {self.buffer[self.write_Index]} R_Data : {self.buffer[self.read_Index]}")
        if self.isFull():
            print("Buffer is full, overwriting the first element")
            self.read_Index = (self.read_Index + 1)% self.max_len
            
            
        self.buffer[self.write_Index] = data
        self.write_Index = (self.write_Index + 1) % self.max_len
        self.count = min(self.count + 1, self.max_len)
        print(f"Read Index : {self.read_Index} Write Index : {self.write_Index} W_Data : {self.buffer[self.write_Index]} R_Data : {self.buffer[self.read_Index]}")
        print()
        
    def dequeue(self):
        if self.isEmpty():
            print("buffer is empty")
            return
        
        data = self.buffer[self.read_Index]
        self.read_Index = (self.read_Index + 1)%self.read_Index
        self.count -=1
        return data
    
    def display(self):
        if self.isEmpty():
            print("Buffer is empty!")
            return

        print("Circular Buffer:", end=" ")
        index = self.read_Index
        for _ in range(self.count):
            print(self.buffer[index], end=" -> ")
            index = (index + 1) % self.max_len
        print("(End)")
        
cb = CircularBuffer(5)
cb.enqueue(1)
cb.enqueue(2)
cb.enqueue(3)
cb.enqueue(4)
cb.enqueue(5)
cb.enqueue(6)

cb.display()
    
            
           
    