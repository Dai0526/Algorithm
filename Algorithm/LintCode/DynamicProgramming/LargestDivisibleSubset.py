"""
603. Largest Divisible Subset
https://www.lintcode.com/problem/largest-divisible-subset/
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

Example 1:
Input: nums =  [1,2,3], 
Output: [1,2] or [1,3]

Example 2:
Input: nums = [1,2,4,8], 
Output: [1,2,4,8]

Notice
If there are multiple solutions, return any subset is fine.
解题 - 接龙型动态规划 - 小模板 记住
因为输出结果要从小到大，并且后一个数要能整除前一个数，所以最后要排序
由前往后，看是否能整除，弱能则记录一个count, 并且需要把一个数组来记录index


"""

class Solution:
    """
    @param: nums: a set of distinct positive integers
    @return: the largest subset 
    """
    def largestDivisibleSubset(self, nums):
        nums.sort()
        size = len(nums)

        lut = [1] * size
        prev = [-1] * size

        #笨方法，循环前面对数组，如果能mod，就加入
        for i in range(size):
            for j in range(i):
                if nums[i] % nums[j] == 0 and lut[i] < lut[j] + 1:
                    lut[i] = lut[j] + 1
                    prev[i] = j

        path = []
        longest_path = max(lut)
        last_idx = lut.index(longest_path)

        while last_idx != -1:
            path.append(nums[last_idx])
            last_idx = prev[last_idx]

        return path


    def largestDivisibleSubset_fast(self, nums):
        nums.sort()
        size = len(nums)

        #use hash as lut, key is last number, value = largest
        lut = {}
        lut = [[1] * size]

        #笨方法，循环前面对数组，如果能mod，就加入
        for i in range(size):
            #单独处理1
            if 1 in lut:
                lut[nums[i]] = max(lut[nums[i]], 2)
            j = 2
            while j * j < nums[i]:
                if nums[i] % j == 0:
                    lut[nums[i]] = max(lut[nums[i]], lut[nums[i] // j] + 1)
                j += 1

        return max(lut)