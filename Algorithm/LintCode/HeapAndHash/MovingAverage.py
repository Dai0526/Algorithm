
"""
642. Moving Average from Data Stream
https://www.lintcode.com/problem/moving-average-from-data-stream/
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // return 1.00000
m.next(10) = (1 + 10) / 2 // return 5.50000
m.next(3) = (1 + 10 + 3) / 3 // return 4.66667
m.next(5) = (10 + 3 + 5) / 3 // return 6.00000
"""

from collections import deque
class MovingAverage:
    """
    @param: size: An integer
    """
    def __init__(self, size):
        # do intialization if necessary
        self.queue = deque()
        self.sum_current = 0
        self.size_current = 0
        self.max_size = size
    """
    @param: val: An integer
    @return:  
    """
    def next(self, val):
        # write your code here
        if self.size_current < self.max_size:
            self.queue.append(val)
            self.sum_current += val
            self.size_current += 1
        else:
            self.sum_current -= self.queue.popleft()       
            self.queue.append(val)
            self.sum_current += val
    
        return self.sum_current/self.size_current
