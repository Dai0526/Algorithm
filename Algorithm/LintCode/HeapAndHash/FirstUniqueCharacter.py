"""
209. First Unique Character in a String
https://www.lintcode.com/problem/first-unique-character-in-a-string/
Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

Example 1:
	Input: "abaccdeff"   Output:  'b'	
	Explanation:
	There is only one 'b' and it is the first one.

Example 2:
	Input: "aabccd" Output:  'b'
	
	Explanation:
	'b' is the first one.
"""

from collections import deque
"""
不要想得太复杂，有一个记录次数，然后再次遍历原字符串即可

提高：怎么改成一个dataStream的class?

Follow up: Problem # 960
"""


class Solution:
    """
    @param str: str: the given string
    @return: char: the first unique character in a given string
    """
    def firstUniqChar(self, str):
        #count all existed string first, then loop over string to find the first count == 1
        counter = {}
        
        for c in str:
            if c in counter:
                counter[c] += 1
            else:
                counter[c] = 1
                
        for c in str:
            if counter[c] != 1:
                continue
            
            return c