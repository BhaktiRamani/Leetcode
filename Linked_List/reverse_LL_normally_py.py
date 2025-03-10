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
        
    def reverse_LL(self):
        prev = None
        current = self.head
        
        while current != None:
            next = current._next
            current._next = prev
            prev = current
            current = next
        
        self.head = prev
        
         
    def print_ll(self):
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp._next
            
            
ll = LinkedList()
ll.add(1)
ll.add(2)
ll.add(3)
ll.add(4)
ll.add(5)
ll.print_ll()

print()

ll.reverse_LL()

ll.print_ll()
