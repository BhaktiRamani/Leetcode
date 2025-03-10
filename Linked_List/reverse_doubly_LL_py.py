class Node:
    def __init__(self, data):
        self.data = data
        self._prev = None
        self._next = None
        
class doubly_linked_list():
    def __init__(self):
        self.head = None
        
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        
        temp = self.head
        while temp._next != None:
            temp = temp._next
            
        temp._next = new_node
        new_node._prev = temp
        
    def insert_at_begin(self, data):
        new_node = Node(data)
        if self.head != None:
            new_node._next = self.head
            self.head = new_node
            return
        self.head = new_node
        
        
    def insert_at_index(self, data, index):
        if index == 1:
            self.insert_at_begin(data)
            return

        temp = self.head
        position = 0
        
        while position != index - 2 and temp != None:
            position+=1
            temp = temp._next
            print(f"Position : {position} Temp.data : {temp.data} Temp.next.data : {temp._next.data}")
            
            
        print(f"Temp._next.data : {temp._next.data} temp._prev.data {temp._prev.data}")
        new_node = Node(data)
        new_node._next = temp._next
        new_node._prev = temp
        if temp._next is not None:
            temp._next._prev = new_node
        temp._next = new_node
        print(f"new_node.data : {new_node.data} new_node._next.data : {new_node._next.data} new_node._prev.data {new_node._prev.data}")
        
    def reverse_LL(self):
        current = self.head
        
        while current != None:
            next = current._next
            current._next = current._prev
            current._prev = current
            current = next
           
            
        self.head = current
            
        
            
            
        
    def print_ll(self):
        temp = self.head
        while temp != None:
            print(temp.data)
            temp = temp._next
            
            
d_ll = doubly_linked_list()

d_ll.insert_at_begin(1)
d_ll.insert_at_end(2)
d_ll.insert_at_end(3)
d_ll.insert_at_end(4)
d_ll.insert_at_end(5)

d_ll.print_ll()
d_ll.reverse_LL()

d_ll.print_ll()
            
        