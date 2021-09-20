"""
76. Longest Increasing Subsequence
https://www.lintcode.com/problem/longest-increasing-subsequence/
Given a sequence of integers, find the longest increasing subsequence (LIS).
You code should return the length of the LIS.

Example 1:
	Input:  [5,4,1,2,3]
	Output:  3
	
	Explanation:
	LIS is [1,2,3]

Example 2:
	Input: [4,2,4,5,3,7]
	Output:  4
	
	Explanation: 
	LIS is [2,4,5,7]
Challenge
Time complexity O(n^2) or O(nlogn)

Clarification
What's the definition of longest increasing subsequence?
The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.
https://en.wikipedia.org/wiki/Longest_increasing_subsequence

思路 - 接龙型动态规划 - 小模板 记住
跳桩子，不停往上跳
任意一点可以为起点，任意一点可以为结束点

lut[i] 标识从左到右至 i这个位置的LIS有多长

转换方程 
之前任意一个比现在的点要小的点中，最大的已知跳跃次数， 然后加上自己的个数 1
lut[i] = max(lut[j], {j = 0 to i - 1 and num[j] < num[i]} + 1)

初始化
因为每个点都有可能是起点，所以1

返回终点
max(lut[])

"""

class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        if not nums:
            return 0

        size = len(nums)
        lut = [1] * size

        for i in range(size):
            for j in range(i):
                if nums[j] < nums[i]:
                    lut[i] = max(lut[i], lut[j] + 1)

        return max(lut)

    """
    Follow up, 打印输出结果
    用另一个数组, 用来记录当前节点取的最大值的前一个节点的idx
    
    转换方程的变化为
    如果 前一个数比我小，并且他的长度也比我小一级（1），那么他就是我的前一位
     if nums[j] < nums[i] and lut[j] + 1 > lut[i]:
                    lut[i] = lut[j] + 1
                    prev[i] = j


    """
    def getLongestIncreasingSubsequence(self, nums):
        if not nums:
            return 0

        size = len(nums)
        lut = [1] * size
        prev = [-1] * size #用来记录当前节点取的最大值的前一个节点的idx

        for i in range(size):
            for j in range(i):
                if nums[j] < nums[i] and lut[j] + 1 > lut[i]:
                    lut[i] = lut[j] + 1
                    prev[i] = j

        # find the index of the longest junp's index
        last = 0
        for i in range(1, size):
            if lut[i] > lut[last]:
                last = i
        # then go over prev list to find each index
        path = []
        while last != -1:
            path.append(nums[last])
            last = prev[last]
        path = path[::-1]

        return path


test = Solution()
seq = [5,4,1,2,3]
print(test.getLongestIncreasingSubsequence(seq))