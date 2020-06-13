
"""
16. Permutations II
https://www.lintcode.com/problem/permutations-ii/
Given a list of numbers with duplicate number in it. Find all unique permutations.

Example 1:
Input: [1,1] 
Output:
[
  [1,1]
]

Example 2:
Input: [1,2,2] 
Output:
[
  [1,2,2],
  [2,1,2],
  [2,2,1]
]

Challenge
Using recursion to do it is acceptable. If you can do it without recursion, that would be great!
"""

class Solution:
    """
    @param: :  A list of integers
    @return: A list of unique permutations


    IDEA:
    如何去重？通过先排序， 用一个map来记录已经录入的值，然后依次去重即可
    Sort first such that is s easier to use index to skip duplicated

    using a set visited to record the visiability for each index

    Core code to skip duplicated 
            if visited[i]:
                continue
            
            if i > 0 and nums[i] == nums[i-1] and visited[i-1]:
                continue
    
    Mark visited when push in and unvisited when pop out

    """

    def permuteUnique(self, nums):
        if nums is None:
            return []
        result = []
        visited = { n : False for n in range(len(nums)) }
        self.permuteUniqueHelper(sorted(nums), visited, [], result)
        
        return result
        
    def permuteUniqueHelper(self, nums, visited, permutation, result):
        #递归的定义 - 找到所有permutation的开头的排列，放入result
        
        #递归的退出 - 如果每一个permutation的长度跟nums相同，则这一次的全排列结束
        if len(nums) == len(permutation):
            result.append(list(permutation))
            return
        
        #递归的拆解
        for i in range(len(nums)):
            
            if visited[i]:
                continue
            
            if i > 0 and nums[i] == nums[i-1] and visited[i-1]:
                continue
            
            visited[i] = True
            permutation.append(nums[i])
            self.permuteUniqueHelper(nums, visited, permutation, result)
            permutation.pop()
            visited[i] = False