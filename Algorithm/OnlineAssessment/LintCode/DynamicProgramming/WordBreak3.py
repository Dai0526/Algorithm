"""
683. Word Break III
https://www.lintcode.com/problem/word-break-iii/
Give a dictionary of words and a sentence with all whitespace removed, return the number of sentences you can form by inserting whitespaces to the sentence so that each word can be found in the dictionary.

Example1
Input: "CatMat"
["Cat", "Mat", "Ca", "tM", "at", "C", "Dog", "og", "Do"]
Output: 3
Explanation:
we can form 3 sentences, as follows:
"CatMat" = "Cat" + "Mat"
"CatMat" = "Ca" + "tM" + "at"
"CatMat" = "C" + "at" + "Mat"
Example1

Input:
"a" []
Output: 0

Notice
Ignore case
"""

"""
算法：DP(动态规划)
根据题目给出的描述，我们稍加思考，可以意识到对于句子s，我们可以拆分成s1和s2，
那么根据乘法原理，s的拆分方法数就等于s1的拆分方法数乘以s2的拆分方法数，
由此我们想到动态规划。

算法思路
我们定义状态dp[i][j]表示s[i:j+1]的拆分方法数
lut[i][j] += lut[i][k] * lut[k+1][j]

代码思路
本题忽略大小写，所以先将所有字符转化为小写
先将dict中与s的子串匹配，计算出初始的dp数组
枚举i和j，即s的所有子串，再枚举分割位置k计算出每一个子串的拆分方法数
返回答案dp[0][n-1]
复杂度分析
空间复杂度：O(N^2)
时间复杂度：O(N^3)

1 1 1 0 0 0 
0 0 1 0 0 0 
0 0 0 1 0 0
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
---->
1 1 2 1 0 3
0 0 1 0 0 1
0 0 0 1 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0

"""


class Solution:
    """
    @param: : A string
    @param: : A set of word
    @return: the number of possible sentences.
    """

    def wordBreak3(self, s, dict):
        
        if not s or not dict:
            return 0
            
        str_size = len(s)
        s_lower = s.lower()     
        #hashset 
        hset = set()
        
        for word in dict:
            hset.add(word.lower())
              
        #init look up table    
        lut = [[0 for i in range(str_size)] for j in range(str_size)]
        
        for i in range(str_size):
            for j in range(i, str_size):
                temp = s_lower[i:j+1]
                if temp in hset:
                    lut[i][j] = 1
        self.pring_range(lut, str_size)

        for i in range(str_size):
            for j in range(i, str_size):
                for k in range(i, j):
                    lut[i][j] += lut[i][k] * lut[k+1][j]

        self.pring_range(lut, str_size)

        return lut[0][str_size - 1]

    def pring_range(self, lut, size):
        for i in range(size):
            s = ""
            for j in range(size):
                s += str(lut[i][j]) + " "
            print(s)




test = Solution()
string = "CatMat"
dictionary = ["Cat","Mat","Ca","tM","at","C","Dog","og","Do"]
test.wordBreak3(string, dictionary)