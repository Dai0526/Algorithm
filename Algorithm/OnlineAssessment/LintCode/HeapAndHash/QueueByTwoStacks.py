"""
40. Implement Queue by Two Stacks
https://www.lintcode.com/problem/implement-queue-by-two-stacks
As the title described, you should only use two stacks to implement a queue's actions.
The queue should support push(element), pop() and top() where pop is pop the first(a.k.a front) element in the queue.
Both pop and top methods should return the value of first element.

Example
Input:
    push(1)
    pop()    
    push(2)
    push(3)
    top()    
    pop()     
Output:
    1
    2
    2

Example 2:
Input:
    push(1)
    push(2)
    push(2)
    push(3)
    push(4)
    push(5)
    push(6)
    push(7)
    push(1)
Output:
[]

Challenge
implement it by two stacks, do not use any other data structure and push, pop and top should be O(1) by AVERAGE.
Notice
Suppose the queue is not empty when the pop() function is called.
"""

class MyQueue:
    
    def __init__(self):
        # do intialization if necessary
        self.container_stack = [] # to put incoming element
        self.working_stack = [] # "queue"
        

    """
    @param: element: An integer
    @return: nothing
    """
    def push(self, element):
        # write your code here
        self.container_stack.append(element)

    """
    @return: An integer
    """
    def pop(self):
        self.makeQueue()  
        return self.working_stack.pop()
        
    """
    @return: An integer
    """
    def top(self):
        self.makeQueue()        
        working_size = len(self.working_stack)
        return self.working_stack[working_size - 1]

    """
    A better practice to clean up code
    """
    def makeQueue(self):
        if len(self.working_stack) == 0:
            container_size = len(self.container_stack)
            while container_size != 0:
                # put all waiting element to stack2 for FIFO order
                self.working_stack.append(self.container_stack.pop()) 
                container_size -= 1
