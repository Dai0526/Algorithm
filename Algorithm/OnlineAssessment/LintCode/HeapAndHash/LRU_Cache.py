"""

Function like a queue, first in, first out
But, if it is either set or get, take it out and push to the last -> recent used.

since move/delete op is frequently, linked list will be a good choice

"""

class LinkedNode:
    def __init__(self, k = None, v = None, nxt_node = None, prev_node = None):
        self.key = k
        self.value = v
        self.next = nxt_node
        self.prev = prev_node

class LRUCache:
    """
    @param: capacity: An integer
    """
    def __init__(self, capacity):
        # do intialization if necessary
        self.key_set = {}
        self.cap = capacity
        self.head = LinkedNode()
        self.tail = LinkedNode()

        self.head.next = self.tail
        self.tail.prev = self.head

    """
    @param: key: An integer
    @return: An integer
    """
    def get(self, key):
        if key not in self.key_set:
            return -1
            
        temp = self.head
        while temp.next is not None:
            if temp.key == key:
                break
            temp = temp.next

        self.move_to_tail(temp)

        return self.tail.prev.value
        
    """
    @param: key: An integer
    @param: value: An integer
    @return: nothing
    """
    def set(self, key, value):
        # write your code here
        if key in self.key_set:
            # find the node
            temp = self.head
            while temp.next is not None:
                if temp.key == key:
                    break
                temp = temp.next
            temp.value = value
            self.key_set[key] = value
            self.move_to_tail(temp)    
        else:
            if len(self.key_set) == self.cap:
                self.pop_front()

            # put to map
            self.key_set[key] = value
            # 
            new_node = LinkedNode(key, value)
            self.tail.prev.next = new_node
            new_node.prev = self.tail.prev
            new_node.next = self.tail
            self.tail.prev = new_node
                
                

    def pop_front(self):
        key = self.head.next.key
        val = self.head.next.value

        print("Pop front: [{},{}]".format(key, val))

        del self.key_set[self.head.next.key]
        self.head.next = self.head.next.next
        self.head.next.prev = self.head

            
    def move_to_tail(self, current):
        
        current.prev.next = current.next
        current.next.prev = current.prev
        
        current.prev = self.tail.prev
        self.tail.prev.next = current
    
        current.next = self.tail
        self.tail.prev = current

    def print_set(self):
        print(self.key_set)

    def print_list(self):
        curr = self.head
        while curr:
            print("[{},{}]".format(curr.key, curr.value))
            curr = curr.next
    

#test = LRUCache(2)
#test.set(2, 1)
#test.set(1, 1)
#val1 = test.get(2)
#print("val1 = {}".format(val1))
#test.set(4, 1)
#val2 = test.get(1)
#print("val2 = {}".format(val2))
#test.get(2)

test = LRUCache(10)
test.set(7, 28)
test.set(7, 1)
#test.set(8, 15)

test.print_list()
test.print_set()
