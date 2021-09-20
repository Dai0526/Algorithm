
"""
200. Longest Palindromic Substring
https://www.lintcode.com/problem/longest-palindrome/
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example 1:
Input:"abcdzdcab", Output:"cdzdc"

Example 2:
Input:"aba", Output:"aba"

Challenge
O(n2) time is acceptable. Can you do it in O(n) time.
"""

class longestPalindromeSubString:
    """
    @param s: input string
    @return: the longest palindromic substring
    """
    def longestPalindrome(self, s):
        # write your code here
        
        size = len(s)
        if size == 1:
            return s
            
        idx_head, idx_tail = 0, 0
        
        # for each character, do a check
        for idx in range(size):
            #deal with even number case
            idx_head, idx_tail = self.CheckPali(idx, idx + 1, idx_head, idx_tail, s, size)       
            # deal with odd size cases
            idx_head, idx_tail = self.CheckPali(idx, idx, idx_head, idx_tail, s, size)
        
        return s[idx_head : idx_tail + 1]
        
    
    def CheckPali(self, left, right, max_head, max_tail, s, size):
        max_size = max_tail - max_head + 1       
        while self.validate_boundry(left, right, size):
            if s[left] != s[right]:
                break
            current_size = right - left + 1
            if current_size > max_size:
                max_size = current_size
                max_head = left
                max_tail = right

            left -= 1
            right += 1
        return max_head, max_tail

    def validate_boundry(self, left, right, size):
        return left >=0 and right < size

    """
    Better practice
    """
    def longestPalindrome_neat(self, s):
        # 重点1：任何代码都要进行异常检测
        if not s:
            return ""
        
        # 重点2：用空行区分开异常检测部分，核心代码部分，和返回值部分，属于高端代码风格技巧
        longest = ""
        for middle in range(len(s)):
            # 重点3：子函数化避免重复代码
            sub = self.find_palindrome_from(s, middle, middle)
            # 重点4：通过返回值来避免使用全局变量这种不好的代码风格
            if len(sub) > len(longest):
                longest = sub
            sub = self.find_palindrome_from(s, middle, middle + 1)
            if len(sub) > len(longest):
                longest = sub
                
		# 重点2：用空行区分开异常检测部分，核心代码部分，和返回值部分，属于高端代码风格技巧
        return longest
        
    def find_palindrome_from(self, string, left, right):
        while left >= 0 and right < len(string):
            # 重点5：将复杂判断拆分到 while 循环内部，而不是放在 while 循环中，提高代码可读性
            if string[left] != string[right]:
                break
            left -= 1
            right += 1
            
        return string[left + 1:right]