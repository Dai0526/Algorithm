
"""
667. Longest Palindromic Subsequence
https://www.lintcode.com/problem/longest-palindromic-subsequence/
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example1

Input: "bbbab" Output: 4
Explanation:
One possible longest palindromic subsequence is "bbbb".

Example2
Input: "bbbbb" Output: 5
"""

class Solution:
    """
    @param s: the maximum length of s is 1000
    @return: the longest palindromic subsequence's length
    """
    def longestPalindromeSubseq(self, s):
        if not s:
            return 0
            
        # using dp to solve it
        str_len = len(s)
        lut = [[0 for i in range(str_len)] for j in range(str_len)]

        # Fill table with length 1 palidrom -> in table i = j
        for i in range(str_len):
            lut[i][i] = 1


        #if traceback the lut , you will see it goes from bottom to top
        for i in range(str_len - 1, -1, -1):
            for j in range(i + 1, str_len):
                if s[i] == s[j]:
                    lut[i][j] = lut[i + 1][j - 1] + 2
                else:
                    lut[i][j] = max(lut[i + 1][j], lut[i][j - 1])

        return lut[0, str_len - 1]