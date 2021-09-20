"""
582. Word Break II
https://www.lintcode.com/problem/word-break-ii
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.

Example 1:
Input："lintcode"，["de","ding","co","code","lint"]
Output：["lint code", "lint co de"]
Explanation：
insert a space is "lint code"，insert two spaces is "lint co de".

Example 2:
Input："a"，[]
Output：[]
Explanation：dict is null.

思路：
要找到所有的组合， DFS， 考虑到速度问题，可以用一个record数据结构来存储当前的match结果，
record 需要是 str, []的结构, 其中：
    1. str是这个[]的seriazition
    2. []是dict的组合

返回值：
返回 list dict种单词的组合

递归的出口：
1. 剩下的str已经在record里了，返回这个能构成这个str的list ? 如何去重
2. 如果str 是空， 说明前面的（原string)已经完成match， 返回一个空的list

循环查找：abcde
如果abcde本身在dict里，加入abcde
对于每一个子字符串  a, ab, abc, abcd
    举例 a
    如果 a 不在dict里，那直接continue到下一个子字符串
    如果 a 在dict里，加入record, 并传递到dfs(bcde, dic, new_record)
把dfs的返回值加上之前的word变成一个string，然后存储到record中

最后返回的是list[list[]]

如何理解
每次打印record的结果如下
{'de': ['de']}
{'de': ['de'], 'code': ['code', 'co de']}
{'de': ['de'], 'code': ['code', 'co de'], 'lintcode': ['lint code', 'lint co de']}

recursion的概念是bottom up，
过程分解，最后组合
lintcode 
    -> lint 
        -> code  其中一个出口如果在dict中就直接append 
        -> co
            -> de
回溯
"co de"
"code" "co de"
“lint code" "lint co de"

"""

class Solution:
    """
    @param: s: A string
    @param: wordDict: A set of words.
    @return: All possible sentences.
    """
    def wordBreak(self, s, wordDict):
        record = {}
        return self.dfs(s, wordDict, record)

    def dfs(self, s, wordDict, record):
        
        if s in record: # 出口1 
            return record[s]
        if len(s) == 0: # 出口2 
            return []
        
        current = []

        if s in wordDict:
            current.append(s)

        #substring must have length 1, so the end idx starts from 1
        for i in range(1, len(s)):
            temp = s[:i]
            if temp not in wordDict:
                continue
            
            remain = s[i:]
            remain_result = self.dfs(remain, wordDict, record)
            
            for word in remain_result:
                #temp can be a part of all the remain_result
                current.append(temp + " " + word)
        record[s] = current
        print(record)
        return current


test = Solution()
string = "lintcode"
dictword = ["de","ding","co","code","lint"]
#Output：["lint code", "lint co de"]    
ans = test.wordBreak(string, dictword)
print(ans)