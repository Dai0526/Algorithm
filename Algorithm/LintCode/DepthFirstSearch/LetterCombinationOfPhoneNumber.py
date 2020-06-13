
"""
425. Letter Combinations of a Phone Number
https://www.lintcode.com/problem/letter-combinations-of-a-phone-number/
Given a digit string excluded 0 and 1, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Example 1:
Input: "23" Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
Explanation: 
'2' could be 'a', 'b' or 'c'
'3' could be 'd', 'e' or 'f'

Example 2:
Input: "5" Output: ["j", "k", "l"]

Notice
Although the answer above is in lexicographical order, your answer could be in any order you want.

"""

class Solution:
    """
    @param digits: A digital string
    @return: all posible letter combinations
    """
    def letterCombinations(self, digits):
        if digits is None or len(digits) == 0:
            return []
        
        # if it all digits can use enum to make it more clear
        # better practice in python might be define a constants class for it
        self.CHAR_MAP = {'2' : 'abc', 
                         '3' : 'def', 
                         '4' : 'ghi', 
                         '5' : 'jkl', 
                         '6' : 'mno', 
                         '7' : 'pqrs', 
                         '8' : 'tuv', 
                         '9' : 'wxyz'}
        result = []
        
        # dfs - solve it recursively
        self.lcHelper(digits, 0, [], result)
        return result
        
    def lcHelper(self, digits, idx, combinations, result):
        if idx == len(digits):
            result.append(''.join(combinations))
            return
        
        for c in self.CHAR_MAP[digits[idx]]:
            combinations.append(c)
            self.lcHelper(digits, idx + 1, combinations, result)
            combinations.pop()
