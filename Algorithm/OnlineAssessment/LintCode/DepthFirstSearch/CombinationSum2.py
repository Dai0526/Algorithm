"""
153. Combination Sum II
https://www.lintcode.com/problem/combination-sum-ii
Given an array num and a number target. Find all unique combinations in num where the numbers sum to target.

Example 1:

Input: num = [7,1,2,5,1,6,10], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
Example 2:

Input: num = [1,1,1], target = 2
Output: [[1,1]]

Explanation: The solution set must not contain duplicate combinations.

Each number in num can only be used once in one combination.
All numbers (including target) will be positive integers.
Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak)
Different combinations can be in any order.
The solution set must not contain duplicate combinations.
"""

class Solution:
    """
    @param num: Given the candidate numbers
    @param target: Given the target number
    @return: All the combinations that sum to target
    """
    def combinationSum2(self, num, target):
        # write your code here

        if target < 0:
            return []
            
        result = []
        # sort to ascending order fistr
        self.combSumHelper(sorted(num), target, 0, [], result)
        
        return result
        
    def combSumHelper(self, candidates, target, idx, combination, result):
        # dfs, go through all 
        if target == 0:
            result.append(list(combination))
            return
        
        for i in range(idx, len(candidates)):
            
            if target < candidates[i]:
                # not found, exit
                return
            
            if i > idx and candidates[i] == candidates[i-1]:
                # skip duplicate candidates
                continue
            
            combination.append(candidates[i])
            #和Sum1的区别在于不能重复使用已有元素，所以start index要从i+1开始循环递归
            self.combSumHelper(candidates, target - candidates[i], i + 1, combination, result)
            combination.pop()