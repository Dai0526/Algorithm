"""
4. Ugly Number II
https://www.lintcode.com/problem/ugly-number-ii/
Ugly number is a number that only have prime factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Input: 9 Output: 10
Input: 1 Output: 1

Challenge
O(n log n) or O(n) time.
"""

"""
Idea 1: use three parameter to record the index has not been multiply by factor
every time take the min, and increment the corresponding idx, add to list.

Once n times, finished, return the tail value in the list.


Idea 2: use heap to save record, and use a set to remove duplicated

"""
import heapq
class Solution:
    """
    @param n: An integer
    @return: return a  integer as description.
    """
    def nthUglyNumber_3idx(self, n):
        # write your code here
        ugly_number = [1]
        
        # idx which has not beed multiple by corresponding factor
        f2_idx = 0
        f3_idx = 0
        f5_idx = 0
        
        while len(ugly_number) < n:
            num = min(ugly_number[f2_idx] * 2, ugly_number[f3_idx] * 3, ugly_number[f5_idx] * 5)
            ugly_number.append(num)
            if num == ugly_number[f2_idx] * 2:
                f2_idx += 1
            if num == ugly_number[f3_idx] * 3:
                f3_idx += 1
            if num == ugly_number[f5_idx] * 5:
                f5_idx += 1
                
        return ugly_number[-1]

    def nthUglyNumber_heap(self, n):
        heap = [1]
        visited = set([1])
        
        val = None
        for _ in range(n):
            val = heapq.heappop(heap)
            for factor in [2, 3, 5]:
                if val * factor not in visited:
                    visited.add(val * factor)
                    heapq.heappush(heap, val * factor)           
        return val