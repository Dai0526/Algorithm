"""
192. Wildcard Matching
https://www.lintcode.com/problem/wildcard-matching
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1
Input:
"aa"
"a"
Output: false

Example 2
Input:
"aa"
"aa"
Output: true

Example 3
Input:
"aaa"
"aa"
Output: false

Example 4
Input:
"aa"
"*"
Output: true
Explanation: '*' can replace any string

Example 5
Input:
"aa"
"a*"
Output: true

Example 6
Input:
"ab"
"?*"
Output: true
Explanation: '?' -> 'a' '*' -> 'b'

Example 7
Input:
"aab"
"c*a*b"
Output: false

Notice
1<=|s|, |p| <= 1000
It is guaranteed that 𝑠 only contains lowercase Latin letters and p contains lowercase Latin letters , ? and *

思路：
DFS 每次检查一个character
1. 如果是*  ->  两个分支 1. string往后走一位，继续和*比较
                       2.  pattern后走一位，因为*可以是空
2. 如果不是* -> 一个分支： 均往后走一位

递归的出口：
1. 如果src走完了，pattern剩下的是* ->true
                        不是* -> False
2. 如果pattern走完了，src还有，-> False

如果只是这么做，会超时，大量的重复工作，所以要去剪枝，增加一个数据结构来存储，并且增加一个recursion的出口
比如说纪录  (sidx, pidx)这一组是否能match，如果在之前的recursion种mathched过，直接返回之前测试的结果

--》 所以用一个hash map来存储符合要求  (i,j) True/False

"""
class Solution:
    """
    @param s: A string 
    @param p: A string includes "?" and "*"
    @return: is Match?
    """
    def isMatch(self, s, p):
        # write your code here
        checked_record = {}
        return self.dfs(s, 0, p, 0, checked_record)


    def dfs(self, src, sidx, pattern, pidx, record):   
        # new memorization exit
        if (sidx, pidx) in record:
            return record[(sidx, pidx)]

        #exit recursion 1
        if sidx == len(src):
            for i in range(pidx, len(pattern)):
                if pattern[i] != '*':
                    return False
            return True

        # recursion exit 2
        if pidx == len(pattern):
            return False

        if pattern[pidx] == '*':
            isMatched = self.dfs(src, sidx + 1, pattern, pidx, record) or self.dfs(src, sidx, pattern, pidx + 1, record)
        else:
            isMatched = self.dfs(src, sidx + 1, pattern, pidx + 1, record) and self.match_char(pattern[pidx], src[sidx])

        # save record
        record[(sidx, pidx)] = isMatched

        return isMatched

    def match_char(self, p_char, src_char):
        return p_char == src_char or p_char == '?'