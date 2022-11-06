from CNode import CNode

class CircularLinkedList:
    def __init__(self, head :CNode, tail: CNode, size:int):
        self.head = None
        self.tail = None
        self.size = 0
        
    def get_head(self) -> CNode:
        return self.head
        
    def get_tail(self) -> CNode:
        return self.tail
        
    def get_size(self) -> int:
        return self.size
        
    def get_node(self, index:int)->CNode:
        if(index < 0 or index >= self.size):
            raise Exception("Invalid exception at get_node()")
            
        iterator = 0
        current = self.head
        while(iterator < index):
            current = current.next_ptr
            iterator +=1
        
        return current
        
    def get(self, index:int):
        return self.get_node(index).data
        
    def index_of(self, item):
        for i in range(self.size):
            if self.get(i) == item:
                return i
        return -1
    
        
    def add(self, index:int, item):
        #Case 1: Invalid Index
        #Case 2: Add to an empty list
        #Case 3: Add to the head of the list 
        #Case 4: Add to the tail of the list
        #Case 5: Add anywhere between the head and tail of the list
        if(index < 0 or index > self.size):
            raise Exception("Invalid exception at add()")
            
        holder_node = CNode(None, item)
        
        if(self.size == 0):
            self.head = self.tail = holder_node
        elif(index == 0):
            holder_node.next_ptr = self.head
            self.head = holder_node
        elif(index == self.size):
            holder_node.next_ptr = self.head
            self.tail.next_ptr = holder_node
            self.tail = holder_node
        else:
            before_node = self.get_node(index - 1)
            holder_node.next_ptr = before_node.next_ptr
            before_node.next_ptr = holder_node
        
        self.size += 1
        
    def add_to_head(self, item):
        self.add(0, item)
        
    def add_to_tail(self, item):
        self.add(self.size, item)
        
    def remove(self, index):
        #Case 1: Invalid Index
        #Case 2: Remove the last item in the list
        #Case 3: Remove the head
        #Case 4: Remove the tail
        #Case 5: Remove anywhere between head and tail
        to_return = self.get(index)
        if(index < 0 or index >= self.size):
            raise Exception("Invalid index from remove()")
            
        if(self.size == 1):
            self.head = self.tail = None
        elif(index == 0):
            self.tail.next_ptr = self.head.next_ptr
            self.head = self.head.next_ptr
        elif(index == self.size - 1):
            before_tail = self.get_node(self.size - 2)
            before_tail.next_ptr = self.head
            self.tail = before_tail
        else:
            before = self.get_node(index - 1)
            before.next_ptr = before.next_ptr.next_ptr
        
        self.size -= 1
        return to_return
        
    def remove_item(self, item):
        return self.remove(self.index_of(item))
        
    def remove_head(self):
        return self.remove(0)
        
    def remove_tail(self):
        return self.remove(self.size - 1)
    
    def to_string(self) -> str:
        to_return  = ""
        for i in range(self.size):
            to_return += str(self.get(i)) + " <--> "
            
        return to_return + str(self.get(0))
    
    


circ_list = CircularLinkedList(None, None, 0)

circ_list.add(0, 11)
circ_list.add(0, 24)
circ_list.add(0, 33)
circ_list.add(0, 41)
#41 <--> 33 <--> 24 <--> 11 <--> 41
print(circ_list.to_string())
circ_list.add_to_head(17)
circ_list.add_to_tail(19)
#17 <--> 41 <--> 33 <--> 24 <--> 11 <--> 19 <--> 17
print(circ_list.to_string())
print(circ_list.index_of(41))
circ_list.remove(circ_list.index_of(41))
#17 <--> 33 <--> 24 <--> 11 <--> 19 <--> 17
print(circ_list.to_string())

circ_list.remove_head()
circ_list.remove_tail()
#33 <--> 24 <--> 11 <--> 33
print(circ_list.to_string())
