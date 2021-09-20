"""
680. Split String
https://www.lintcode.com/problem/split-string/description?_from=ladder&&fromId=1
Give a string, you can choose to split the string after one character or two adjacent characters, and make the string to be composed of only one character or two characters. Output all possible results.

Example1
Input: "123"
Output: [["1","2","3"],["12","3"],["1","23"]]
Example2

Input: "12345"
Output: [["1","23","45"],["12","3","45"],["12","34","5"],["1","2","3","45"],["1","2","34","5"],["1","23","4","5"],["12","3","4","5"],["1","2","3","4","5"]]
"""
import time
class SplitString:
    """
    @param: : a string to be split
    @return: all possible split string array
    """
    
    def splitString(self, s):
        # write your code here
        result = []
        self.splitStrHelper(s, 0, [], result)
        return result
    
    def splitStrHelper(self, s, idx, substring, result):
        if idx >= len(s):
            result.append(list(substring))
            return
        
        for i in range(idx, idx + 2):
            if i + 1 <= len(s):
                substring.append(s[idx : i + 1])
                self.splitStrHelper(s, i + 1, substring, result)
                substring.pop()
    """
        做为一道练习DFS的题，不奇怪所有的上传都是DFS，无一例外。
        但是，你要是面试碰到这题，立刻无脑的写个DFS出来，会有问题的。
        这里DFS递归里，和Fibonacci的递归类似，是有重复的。有一个同学注意到了，所以用了memo。但是这memo的代价很大。
        其实，和Fibonacci一样，你只要记住前俩个子数组就够了。详见代码。
        切记，不要拿练习题的解法当标准答案
    """
    def splitString2(self, s):
        
        n = len(s)      
        if n == 0: return [[]]
        if n == 1: return [[s[:]]]
        
        n_2, n_1 = [[]], [[s[n-1:]]]
        
        for i in range(2, n+1):
            n_0 = []
            for sub in n_2:
                newSub = [s[n-i:n-i+2]] + sub
                n_0.append(newSub)
            for sub in n_1:
                newSub = [s[n-i]] + sub
                n_0.append(newSub)
            n_2, n_1 = n_1, n_0
            
        return n_0


sps = SplitString()

test_str = "12345678901234567890"

start = time.time()
for i in range (10**3):
    res = sps.splitString(test_str)
end = time.time()
print("splitString returns {} and it takes {} mSec. ".format(len(res), end - start))

start = time.time()
for i in range (10**3):
    res2 = sps.splitString2(test_str)
end = time.time()
print("splitString2 returns {} and it takes {} mSec. ".format(len(res2), end - start))
