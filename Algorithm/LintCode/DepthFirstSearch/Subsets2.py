"""
18. Subsets II
https://www.lintcode.com/problem/subsets-ii/description

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Example 1:
Input: [0] Output:
[
  [],
  [0]
]

Example 2:
Input: [1,2,2] Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Challenge
Can you do it in both recursively and iteratively?

Notice
Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.
"""

class Solution:
    """
    @param nums: A set of numbers.
    @return: A list of lists. All valid subsets.
    """
    def subsetsWithDup(self, nums):
        if nums is None:
            return []
        result = []
        self.dfs(sorted(nums), 0, [], result)
        return result
        

    def dfs(self, nums, idx, combination, result):
        result.append(list(combination))
        for i in range(idx, len(nums)):
            
            #remove duplicate 1.same as before and already added
            # if      nums[i] == nums[i-1] && i > start index
            # the  make sure i - 1 >= 0 
            if i > 0 and nums[i] == nums[i-1] and i > idx:
                continue
            combination.append(nums[i])
            self.dfs(nums, i + 1, combination, result)
            combination.pop()
        