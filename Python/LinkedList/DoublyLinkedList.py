from DNode import DNode
class DoublyLinkedList:
    def __init__(self, head, tail, size):
        self.head = None
        self.tail = None
        self.size = 0
     
    def get_head(self):
        return self.head
        
    def get_tail(self):
        return self.tail
        
    def get_size(self):
        return self.size
        
    def get_node(self, index):
        if (index < 0 or index >= self.size):
            raise Exception("Invalid Index")
        count = 0
        current = self.head
        while(count < index):
            current = current.next_ptr
            count +=1
        return current
        
    def get(self, index):
        return self.get_node(index).data
        
    def add(self, index, item):
        #Case 1: Invalid index
        #Case 2: Add to an empty list
        #Case 3: Add to the head
        #Case 4: Add to the tail
        #Case 5: Add to anywhere of the linked list
        if(index < 0 or index > self.size):
            raise Exception('Invalid Index')
        
        holder = DNode(item, None, None)
        
        if(self.size == 0):
            self.head = self.tail = holder
        elif(index == 0):
            holder.next_ptr = self.head
            self.head.prev = holder
            self.head = holder
        elif(index == self.size):
            holder.prev_ptr = self.tail
            self.tail.next_ptr = holder
            self.tail = holder
        else:
            before = self.get_node(index - 1)
            holder.next_ptr = before.next_ptr
            holder.next_ptr.prev_ptr = holder
            holder.prev_ptr = before
            before.next_ptr = holder
               
        self.size +=1
        
    def append_tail(self, item):
        self.add(self.size, item)
    
    def append_head(self, item):
        self.add(0, item)
        
    def search(self, item):
        current = self.head
        index = 0
        while(current):
            if(current.data == item):
                return index
                
            index += 1
            current = current.next_ptr
        
        return -1
        
    def remove(self, index):
        #Case 1: Invalid Index or list is empty
        #Case 2: List has one item left **edge case **
        #Case 3: Remove the head
        #Case 4: Remove the tail
        #Case 5: Remove any position in the linked list
        if(index < 0 or self.size == 0 or index >= self.size):
            raise Exception("Invalid Index or List is empty")
            
        item = self.get(index)
        
        if(self.size == 1):
            self.head = self.tail = None
            
        elif(index == 0):
            self.head = self.head.next_ptr
            self.head.prev_ptr = None
            
        elif(index == self.size - 1):
            self.tail = self.tail.prev_ptr
            self.tail.next_ptr = None
            
        else:
            before = self.get_node(index - 1)
            before.next_ptr = before.next_ptr.next_ptr
            before.next_ptr.prev_ptr = before
            
        self.size -= 1
        return item
    
    def remove_item(self, item):
        return self.remove(self.search(item))
        
    def pop(self):
        return self.remove(self.size - 1)
        
    def pop_head(self):
        return self.remove(0)
        
    def to_string(self):
        to_return = ""
        node = self.head
        while(node):
            to_return += node.data + " <--> "
            node = node.next_ptr
            
        to_return  += "NULL"
        return to_return
    
e =  DNode(1, None, None)
dl = DoublyLinkedList(None, None, 0)
dl.add(0, 'a')
dl.add(1, 'b')
dl.add(1, 'd')
dl.add(2, 'c')
dl.append_tail('s');
print(dl.to_string())
dl.remove(1)
print(dl.to_string())
dl.remove(0)
print(dl.to_string())
dl.remove(dl.get_size() - 1)
print(dl.to_string())
print(dl.search('c'))