"""
15. Permutations
https://www.lintcode.com/problem/permutations/
Given a list of numbers, return all possible permutations.

Example 1:
Input: [1] Output:
[
  [1]
]

Example 2:
Input: [1,2,3]  Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Challenge
Do it without recursion.

Notice
You can assume that there is no duplicate numbers in the list.
"""

class Solution:
    """
    @param: nums: A list of integers.
    @return: A list of permutations.
    """
    def permute(self, nums):
        if nums is None:
            return []
        result = []
        self.dfsPermutationHelper(nums, [], result)
        
        return result
    
    
    
    def dfsPermutationHelper(self, nums, permutation, result):
        #递归的定义 - 找到所有permutation的开头的排列，放入result
        
        #递归的退出 - 如果每一个permutation的长度跟nums相同，则这一次的全排列结束
        if len(nums) == len(permutation):
            result.append(list(permutation))
            return
        
        #递归的拆解, for each 大大提高可读性， 比for range的版本更好理解
        for n in nums:
            if n in permutation:
                continue    # skip duplicate case
            permutation.append(n)
            self.dfsPermutationHelper(nums, permutation, result)
            permutation.pop()