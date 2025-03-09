class fifo_lifo:
    def __init__(self, max_len):
        self.__max_len = max_len
        self._len = 0
        self._buffer = [None]*self.__max_len
            
    def isEmpty(self):
        return self._len == 0
    
    def isFull(self):
        return self.__max_len == self._len
    
    def push(self, data):
        if(not self.isFull()):
            self._buffer[self._len] = data
            self._len += 1
            
    def pop(self):
        if(not self.isEmpty()):
            self._len -= 1
            data = self._buffer[self._len] 
            return data
        
    def print_lifo(self):
        for i in range(self._len):
            print(self._buffer[i], " ")
            
    
        
            
stack = fifo_lifo(128)
stack.push(1)
stack.push(2)
stack.push(3)
stack.push(4)

stack.pop()

stack.print_lifo()


            
            