"""
494. Implement Stack by Two Queues
https://www.lintcode.com/problem/implement-stack-by-two-queues/
Implement a stack by two queues. The queue is first in first out (FIFO). That means you can not directly pop the last element in a queue.


Example 1:
Input:
push(1)
pop()
push(2)
isEmpty() // return false
top() // return 2
pop()
isEmpty() // return true
Example 2:

Input:
isEmpty()

"""
"""
设计数据结构的题，出发点 1. 功能
                        2. 时间复杂度、空间复杂度
该题明显从功能要求出发，两个Queue实现stack, 一个Queue做主要功能，另一个Queue是中间临时存储，用于存放idx = 1之后的item
    
"""


import queue

class Stack:
    
    def __init__(self):
        self.queue_in = queue.Queue()
        self.queue_out = queue.Queue()
    
    """
    @param: x: An integer
    @return: nothing
    """
    def push(self, x):
        self.queue_in.put(x)
        

    """
    @return: nothing
    """
    def pop(self):
        size = self.queue_in.qsize()
        while size != 1:
            self.queue_out.put(self.queue_in.get())
            size -= 1

        
        val = self.queue_in.get()
        #switch two queue
        self.queue_in, self.queue_out = self.queue_out, self.queue_in
        return val
        

    """
    @return: An integer
    """
    def top(self):
        size = self.queue_in.qsize()
        while size != 1:
            self.queue_out.put(self.queue_in.get())
            size -= 1

        val = self.queue_in.get()
        self.queue_out.put(val)
        #switch two queue
        self.queue_in, self.queue_out = self.queue_out, self.queue_in
        return val

    """
    @return: True if the stack is empty
    """
    def isEmpty(self):   
        return self.queue_in.empty()