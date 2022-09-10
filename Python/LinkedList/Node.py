class Node:
    def __init__(self, data, next_ptr):
        self.data = data
        self.next_ptr = None
    def print_str(self):
        print(self.data, self.next_ptr.data, self.next_ptr is None)