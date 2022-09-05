#TODO: Implement a linked list in Python

class LinkedList:
    def __init__(self, head, size):
        self.head = None
        self.size = 0
        
    def get(index):
        pass
    
    def get_node(index):
        pass
        
    def get_size():
        return self.size;
    
    def add(index, item):
        pass
        
    def add(item):
        pass
        
    def remove(index):
        pass
        
    def remove(item):
        pass
    
    def pop():
        pass
    
class Node:
    def __init__(self, data, next_ptr):
        self.data = data
        self.next_ptr = None
    def print_str(self):
        print(self.data, self.next_ptr.data, self.next_ptr is None)
        
e = Node(1, None)
e1 = Node(2, None)
e.next_ptr = e1
e.print_str()