class DNode:
    def __init__(self, data, next_ptr, prev_ptr):
        self.data = data
        self.next_ptr = None
        self.prev_ptr = None
        
    def print_str(self):
        print(self.data, self.next_ptr.data, self.prev_ptr.data, self.next_ptr is None, self.prev_ptr is None)
