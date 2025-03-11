class Node:
    def __init__(self, data):
        self.data = data
        self._next = None
       
        
class LinkedList():
    def __init__(self):
        self.head = None
        
    def add(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            temp = self.head
            while temp._next is not None:
                temp = temp._next
            temp._next = new_node
            
    def insert_at_begin(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        else:
            new_node.next = self.head
            self.head = new_node
            
    def insert_at_index(self, data, index):
        if (index == 0):
            self.insert_at_begin(data)
            return
        
        position = 0
        current_node = self.head
        while position != (index - 2):
            current_node = current_node._next
            position+=1

  
        if current_node != None:
            print(" ")
            new_node = Node(data)
            new_node._next = current_node._next
            current_node._next = new_node
        else:
            print("index not present")
        
    def insert_at_end(self, data):
        temp = self.head
        while temp ._next != None:
            temp = temp._next
            
        new_node = Node(data)
        temp._next = new_node
        
    def update_node(self, data, index):
        if index == 0 and self.head != None:
            self.head.data = data
            return
        
        position = 0
        current_node = self.head
        while position != index - 1 and current_node != None:
            current_node = current_node._next
            position +=1
         
        if current_node != None: 
            current_node.data = data
        else:
            print("index for update not present")
            
    def delete_node(self, index):
        if self.head is None:
            print("Linked List doesn't exist")
            return
        if(index == 1):
            temp = self.head._next
            self.head = temp
            return
        
        if(index == 0xFF):
            current_node = self.head
            while current_node._next._next != None:
                current_node = current_node._next
                
            current_node._next = None
        
        position = 0
        current_node = self.head
        while position != index - 2 and current_node != None:
            current_node = current_node._next
            position += 1
            

        if current_node != None: 
            temp = current_node._next._next
            current_node._next = temp
        else:
            print("index for delete not present")
            
    def delete_head(self):
        self.delete_node(1)
        
    def delete_end(self):
        self.delete_node(0xFF)
        
    def peek(self, index):
        temp = self.head
        position = 0
        while position < index and temp is not None:
            temp = temp._next
            position += 1
        #print(f"peek : {temp.data}")
        
        if temp is not None:
            return temp.data
        else:
            return None
        
    def reverse_LL(self):
        prev = None
        current = self.head
        next = current._next
        
        print(f"Current._next : {current._next}")
        temp = self.head
        while temp._next != None:
            temp = temp._next
            
        prev = temp
        current._next = prev
        print(f"Current._next : {current._next}")
        prev = current
        current = next
        next = current._next
        
         
    def print_ll(self):
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp._next
            
            
            
ll1 = LinkedList()
ll1.add(1)
ll1.add(2)
ll1.add(4)
ll1.peek(2)

ll1.print_ll()

print(" ")
ll2 = LinkedList()
ll2.add(3)
ll2.add(5)
ll2.print_ll()

ll = LinkedList()

for i in range(5):
    if ll1.peek(i) == None or ll2.peek(i) == None:
        break
    if ll1.peek(i) == ll2.peek(i):
        ll.add(ll1.peek(i))
        ll.add(ll2.peek(i))
        
    elif ll1.peek(i) < ll2.peek(i):
        ll.add(ll1.peek(i))
        ll.add(ll2.peek(i))
        
    else:
        ll.add(ll2.peek(i))
        ll.add(ll1.peek(i))
        
print("merged : ")
ll.print_ll()
        
    




            