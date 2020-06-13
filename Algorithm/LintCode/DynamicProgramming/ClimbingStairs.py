"""
111. Climbing Stairs
https://www.lintcode.com/problem/climbing-stairs/
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
	Input:  n = 3
	Output: 3
	
	Explanation:
	1) 1, 1, 1
	2) 1, 2
	3) 2, 1
	total 3.

Example 2:
	Input:  n = 1
	Output: 1
	
	Explanation:  
	only 1 way.

思路
               _5_
           _3_/ 4
       _2_/3
   _1_/2 
__/1
0

第三级 可以通过 第二级 和 第一级 到达，像是一个斐波那契数列，f(n) = f(n-1) + f(n-2)
用动态规划（解决）加上滚动数组（节省空间）就能解决了

"""


class Solution:
    """
    @param n: An integer
    @return: An integer
    """
    def climbStairs(self, n):
        # write your code here
        if n == 0:
            return 0
        if n== 1:
            return 1

        lut = [0, 1, 2]

        for i in range(3, n + 1):
            lut[i % 3] = lut[i % 3 - 1] + lut[i % 3 - 2]

        return lut[n % 3]