"""
415. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example 1:
Input: "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama"

Example 2:
Input: "race a car"
Output: false
Explanation: "raceacar"

Challenge
O(n) time without extra memory.

Notice
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
"""
import re
import time
class ValidPalindrome:

    def IntuitiveSolution(self, s):
        if not s:
            return True
        
        #convert to lower
        s = s.lower()        
        # two pointer move toward each other
        start, end = 0, len(s) - 1
        
        while start < end:
            if not s[start].isalnum():
                start += 1
                continue         
            if not s[end].isalnum():
                end -= 1
                continue       
            #compare two alp num
            if s[start] != s[end]:
                return False              
            start += 1
            end -= 1   
        return True

    def fancySolution(self, s):
        if not s:
            return True
        
        # regx to remove unwanted characters
        s = s.lower()        
        s = re.sub(r'\W+', '', s) # or re.sub(r'[^A-Za-z0-9 ]+', '', s)
        reverse_s = s[::-1] #extra space

        if s == reverse_s:
            return True
        else:
            return False


test = ValidPalindrome()
test_str = "amAna~planaCanal,pAnam a!"
start = time.time()
for i in range (10**6):
    isPali = test.IntuitiveSolution(test_str)
end = time.time()
print("IntuitiveSolution returns {} and it takes {} mSec. ".format(isPali, end - start))

start = time.time()
for i in range (10**6):
    isPali = test.fancySolution(test_str)
end = time.time()
print("fancySolution returns {} and it takes {} mSec. ".format(isPali, end - start))