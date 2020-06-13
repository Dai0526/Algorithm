"""
135. Combination Sum
https://www.lintcode.com/problem/combination-sum/
Given a set of candidtate numbers candidates and a target number target. Find all unique combinations in candidates where the numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Example 1:
Input: candidates = [2, 3, 6, 7], target = 7, Output: [[7], [2, 2, 3]]

Example 2:
Input: candidates = [1], target = 3, Output: [[1, 1, 1]]

All numbers (including target) will be positive integers.
Numbers in a combination a1, a2, … , ak must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak)
Different combinations can be in any order.

The solution set must not contain duplicate combinations.

"""

class Solution:
    """
    @param candidates: A list of integers
    @param target: An integer
    @return: A list of lists of integers
    """
    def combinationSum(self, candidates, target):
        
        if target < 0:
            return []
            
        result = []
        # sort to ascending order fistr
        self.combSumHelper(sorted(candidates), target, 0, [], result)
        
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
            self.combSumHelper(candidates, target - candidates[i], i, combination, result)
            combination.pop()