#TODO: Implement a linked list in Python

class LinkedList:
    def __init__(self, head, size):
        self.head = None
        self.size = 0
        
    def get_head(self):
        return self.head
        
    def get_node(self, index):
        count = 0
        current = self.head
        if(index < 0 or index >= self.size):
            raise Exception('Invalid Index')
        while(count < index):
            current = current.next_ptr
            count +=1

        return current
        
    def get(self, index):
        if(index < 0 or index >= self.size):
            raise Exception('Invalid Index')
            
        return self.get_node(index).data
    
        
    def get_size(self):
        return self.size;
    
    def add(self, index, item):
        if(index < 0 or index > self.size):
            raise Exception('Invalid Index')
        holder = Node(item, None)
        if(self.size == 0):
            holder.next_ptr = self.head
            self.head = holder
        else:
            before = self.get_node(index - 1)
            holder.next_ptr = before.next_ptr
            before.next_ptr = holder
            
        self.size +=1
        
    def append(self, item):
        self.add(self.size, item)
        
    def remove(self, index):
        if(index < 0 or index > self.size):
            raise Exception('Invalid Index')
            
        item_return = self.get(index)
        if(index == 0):
            self.head = self.head.next_ptr
        else:
            before = self.get_node(index - 1)
            before.next_ptr = before.next_ptr.next_ptr
            
        self.size -= 1
        return item_return
        
    
    def search(self, item):
        node = self.head
        count = 0 
        while(node):
            if(node.data == item):
                return count
            count += 1
            node = node.next_ptr
        return -1
            
        
        
    def remove_item(self, item):
        index_to_remove = self.search(item)
        item_to_return = None
        if(index_to_remove != -1):
            item_to_return = self.remove(index_to_remove)
        return item_to_return 
        
    
    def pop(self):
        return self.remove(self.size - 1)
        
    def string(self):
        node = self.head
        string = ""
        while(node):
            string += node.data + "-->"
            node = node.next_ptr
        string += "NULL"
        return string
    
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
l = LinkedList(None, 0)
l.add(0,'a')
l.append('e')
l.append('1')
l.remove(0)
print(l.remove_item('1'))
l.pop()
print(l.string())