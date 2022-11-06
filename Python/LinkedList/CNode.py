class CNode:
    def __init__(self, next_ptr, data):
        self.next_ptr = None
        self.data = data
    
    #For debugging purpose
    def to_string(self):
        return "Data : {data}, Next Pointer Address: {next_pointer}".format(data = self.data, next_pointer = self.next_ptr)
        