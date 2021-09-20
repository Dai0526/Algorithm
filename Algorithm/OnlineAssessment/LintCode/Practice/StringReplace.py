"""
841. String Replace
https://www.lintcode.com/problem/string-replace/
Given two identical-sized string array A, B and a string S. All substrings A appearing in S are replaced by B.(Notice: From left to right, it must be replaced if it can be replaced. If there are multiple alternatives, replace longer priorities. After the replacement of the characters can't be replaced again.)

Example 1
A = ["ab","aba"] B = ["cc","ccc"] S = "ababa"
Output: "cccba"
Explanation: In accordance with the rules, the substring that can be replaced is "ab" or "aba". Since "aba" is longer, we replace "aba" with "ccc". 

Example 2
A = ["ab","aba"] B = ["cc","ccc"] S = "aaaaa"
Output: "aaaaa"
Explanation: S does not contain strings in A, so no replacement is done.

Example 3
A = ["cd","dab","ab"] B = ["cc","aaa","dd"] S = "cdab"
Output: "ccdd"
Explanation: From left to right, you can find the "cd" can be replaced at first, so after the replacement becomes "ccab", then you can find "ab" can be replaced, so the string after the replacement is "ccdd".
"""

class Solution:
    """
    @param a: The A array
    @param b: The B array
    @param s: The S string
    @return: The answer
    """

    """
    暴力解法，如果string长， 运行速度十分慢 O(n^2 * l)
    """
    def stringReplace_slow(self, a, b, s):
        str_len = len(s)
        ab_map = {}
        # create a hashmap for a,b
        for i in range(len(a)):
            ab_map[a[i]] = b[i]
        i = 0
        while i < str_len:
            max_len = 0
            target = ''
            for l in range(i+1, str_len+1):
                temp = s[i:l]
                if temp not in a:
                    continue
                temp_len = len(temp)
                if temp_len > max_len:
                    max_len = temp_len
                    target = temp
            if target:
                #print("front = {}, target = {}, end = {}".format(s[ : i], ab_map[target], s[i + max_len:]))
                s = s[ : i] + ab_map[target] + s[i + max_len:]
                i += max_len
            else:
                i += 1
        return s





test = Solution()

A = ['cd', 'dab','ab']
B = ['cc','aaa', 'dd']
S = 'cdab'
ans = test.stringReplace(A, B, S)
if ans == 'ccdd':
    print("Pass")
else:
    print(ans)


A = ['ab','aba']
B = ['cc','ccc']
S = 'ababa'
ans = test.stringReplace(A, B, S)
if ans == 'cccba':
    print("Pass")
else:
    print(ans)

A = ['ab','aba']
B = ['cc','ccc']
S = 'aaaaa'
ans = test.stringReplace(A, B, S)
if ans == 'aaaaa':
    print("Pass")
else:
    print(ans)

