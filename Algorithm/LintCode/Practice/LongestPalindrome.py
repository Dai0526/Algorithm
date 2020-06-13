"""
627. Longest Palindrome

Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Example

Input : s = "abccccdd"
Output : 7

Explanation :
One longest palindrome that can be built is "dccaccd", whose length is `7`.
Notice:
Assume the length of given string will not exceed 100000.

"""

import time
import collections

class LongestPalindrome:
    # write your code here
    """
    In c++, what I did is:
    1. iterate string, add char to map<c, int> int is count
    2. Iterate Map, if it is even number, length +2
    3. If there is an odd count, set flag to tree.
    4. If odd count flag is true, return count + 1, else return count.
    
    In python, counter_list = collections.Counter(s) is a trick,
    
    """
    # use collections.Counter() to get a dict of counts for each item
    # it saves the code base, but since it create a whole dict, 
    # the O(n) is the same as longestPalindromeSlow version
    def longestPalindromeClean(self, s):
        ans = 0
        cnt = collections.Counter(s) # This is the trick to save code, but runtime is the same
        #print(cnt)
        for i in cnt.values():
            ans += i // 2 * 2
            if ans % 2 == 0 and i % 2 == 1:
                ans += 1
        return ans

    # instead of create a full hash map and iterate again,
    # modified to add to length if found in map
    # set up hashmap
    def longestPalindromeFaster(self, s):

        hash = {}
        length = 0
        
        for c in s:
            if c in hash:
                del hash[c]
                length += 2
            else:
                hash[c] = True

        left = len(hash)
    
        if left > 0:
            return length + 1
    
        return length


    # set up hashmap, iterate it and get count, add to length if is even,
    # if it is odd, add odd_count - 1, set odd flag to true
    def longestPalindromeSlow(self, s):

        hash_map = {}

        for c in s:
            if c in hash_map:
                hash_map[c] += 1
            else:
                hash_map[c] = 1
                
        length = 0
        oddFlag = False
        
        for c, n in hash_map.items():
            if n % 2 == 0:
                length += n
            else:
                length += n // 2 * 2
                oddFlag = True
                
        if oddFlag == True:
            return length + 1
        
        return length



lp = LongestPalindrome()
test_str = "abccccddaaAABBBCCDEFFEDdd"
start = time.time()
for i in range (10**6):
    length = lp.longestPalindromeFaster(test_str)
end = time.time()
print("longestPalindrome Faster version returns {} and it takes {} mSec. ".format(length, end - start))

start = time.time()
for i in range (10**6):
    length = lp.longestPalindromeSlow(test_str)
end = time.time()
print("longestPalindrome Slow Version returns {} and it takes {} mSec. ".format(length, end - start))

start = time.time()
for i in range (10**6):
    length = lp.longestPalindromeClean(test_str)
end = time.time()
print("longestPalindrome Slow Version returns {} and it takes {} mSec. ".format(length, end - start))