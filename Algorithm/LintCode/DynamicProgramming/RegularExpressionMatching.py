"""
154. Regular Expression Matching
https://www.lintcode.com/problem/regular-expression-matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(string s, string p)
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

Example 1:
Input："aa"，"a", Output：false
Explanation：
unable to match

Example 2:
Input："aa"，"a*", Output：true
Explanation：
'*' can repeat a


思路： DP 区间型动态规划 二维数组记录match结果
string aab             len = 3
pattern c*a*b          len = 5
  _ a a b
_ T
c 
*
a
*
b 

初始状态
lut[0][0] = True  // 都是空
初始化所有 *， 如果pattern[n] == '*' && lut[0][n-1] == True -> lut[n][n+1]
        举例 aab <-> c*aab* --->  when n = 1, p[1] == *, set lut[0][2] = True 即c*可以当做是空

1. pattern[j] == string[i] --> 继承上一个的结果 lut[i][j] = lut[i-1][j-1] 
2. pattern[j] == '.' --> 匹配任意单个字符，继承上一个的结果 lut[i][j] = lut[i-1][j-1]   
3. pattern[j] == '*'  需要看前一个 pattern[j-1]
        a. pattern[j-1] ！= string[i] &&  pattern[j-1] != '.'--> lut = lut[i][j-2] 如果不同，
            情况如下 pattern[j-1]pattern[j] 合起来当做是空即 'c*' 整体match ''
        b. pattern[j-1] == string[i] || pattern[j-1] == '.'， 那么
            lut[i][j] == lut[i][j - 1] -> a* 匹配a
            lut[i][j] == lut[i - 1][j] -> a* 匹配 aaaaaa
            lut[i][j] == lut[i][j - 2] -> a* 匹配为 empty

"""

class Solution:
    """
    @param s: A string 
    @param p: A string includes "." and "*"
    @return: A boolean
    """
    def isMatch(self, s, p):

        if not s or not p:
            return False

        str_len = len(s)
        pattern_len = len(p)

        # initialize
        lut = [[False for i in range(0, pattern_len + 1)] for j in range(0, str_len + 1)]
        lut[0][0] = True 
        for i in range(pattern_len):
            if p[i] == '*' and lut[0][i-1] == True:
                lut[0][i+1] = True


        for i in range(str_len):
            for j in range(pattern_len):
                # case 1
                if p[j] == s[i]:
                    lut[i + 1][j + 1] = lut[i][j] #+1是因为table index比string/pattern idx要多1
                if p[j] == '.':
                    lut[i + 1][j + 1] = lut[i][j]

                if p[j] == '*':
                    if p[j - 1] != s[i] and p[j - 1] == '.':
                        lut[i+1][j+1] = lut[i+1][j-1]
                    else:
                        lut[i+1][j+1] = lut[i+1][j] or lut[i][j+1] or lut[i+1][j-1]


        # write your code here
        return lut[str_len][pattern_len]