"""
544. Top k Largest Numbers
https://www.lintcode.com/problem/top-k-largest-numbers/
Given an integer array, find the top k largest numbers in it.

Input: [3, 10, 1000, -99, 4, 100] and k = 3
Output: [1000, 100, 10]

Input: [8, 7, 6, 5, 4, 3, 2, 1] and k = 5
Output: [8, 7, 6, 5, 4]
"""

import heapq

class Solution:
    """
    @param nums: an integer array
    @param k: An integer
    @return: the top k largest numbers in array
    """
    def topk2(self, nums, k):
        # write your code here
        max_heap = []
        for n in nums:
            heapq.heappush(max_heap, n)   
            if len(max_heap) > k:
                heapq.heappop(max_heap)
        
        result = []   
        #maintain a heap with size k  
        while max_heap:
            result.append(heapq.heappop(max_heap))
        result.reverse()  
        return result


    """
        需要对python的stl更了解
    """
    def topk(self, nums, k):
        # Write your code here
        heapq.heapify(nums)
        topk = heapq.nlargest(k, nums)
        topk.sort()
        topk.reverse()
        return topk