"""
607. Two Sum III - Data structure design
https://www.lintcode.com/problem/two-sum-iii-data-structure-design/
Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example
add(1); add(3); add(5);
find(4) // return true
find(7) // return false

"""

"""
两种方法去做
双指针 - list
也可以用map来计数
"""

class TwoSum:
    
    def __init__(self):
        self.m_list = [] # two pointer
        self.m_map = {} # use hash map

        
    def add_map(self, number):
        if number in self.m_map:
            self.m_map[number] += 1
        else:
            self.m_map[number] = 1

    def find_map(self, value):

        for num in self.m_map:
            target = value - num
            
            if target == num and self.m_map[target] > 1:
                return True
            
            if target !=num and target in self.m_map:
                return True
                
        return False

    def add_list(self, number):
        # write your code here
        self.m_list.append(number)

    def find_list(self, value):
        # write your code here
        length = len(self.m_list)
        
        if length < 2:
            return False
            
        self.m_list.sort()
        left, right = 0, length - 1
        while left < right:
            current = self.m_list[left] + self.m_list[right]
            if current == value:
                return True
            
            if current < value:
                left += 1
            else:
                right -= 1

        return False