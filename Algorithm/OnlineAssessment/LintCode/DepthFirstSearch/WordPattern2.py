"""
829. Word Pattern II
https://www.lintcode.com/problem/word-pattern-ii/
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.(i.e if a corresponds to s, then b cannot correspond to s. For example, given pattern = "ab", str = "ss", return false.)

Example:
pattern = "abab", str = "redblueredblue"
true

pattern = "aaaa", str = "asdasdasdasd"
true

pattern = "aabb", str = "xyzabcxzyabc"
false

You may assume both pattern and str contains only lowercase letters.
"""

class Solution:
    """
    @param pattern: a string,denote pattern string
    @param str: a string, denote matching string
    @return: a boolean
    """
    
    """
    since pattern ab, a != b, thus, we need a map to record each pattern
    we also need a map to record strings from pattern
    
    The recursion exit will be:  charA at len(string) && charB at len(pattern)
        if both true, return true
        one of then true , but another goes to end, return False
        
    What each recursion did:
        
    """
    
    def wordPatternMatch(self, pattern, string):
        return self.dfsMatch(pattern, 0, string, 0, {},  set())
    
    def dfsMatch(self, pattern, idx_pattern, string, idx_str, char_to_word_map, used_word_set):
        pattern_len = len(pattern)
        string_len = len(string)

        if idx_pattern == pattern_len and idx_str == string_len:
            return True
        
        if idx_pattern == pattern_len or idx_str == string_len:
            return False
        
        # for each char represents a patter, check if it is already exist     
        char = pattern[idx_pattern]

        if char in char_to_word_map:
            word = char_to_word_map[char]
            #check this pattern is the start of the string
            if not string.startswith(word, idx_str):
                return False            
            return self.dfsMatch(pattern, idx_pattern + 1, string, idx_str + len(word), char_to_word_map, used_word_set)
            
        #if current patter representive not has a match yet, need to find new pattern
        for i in range(idx_str, string_len):
            # get all kinds of possible word from begin
            new_word = string[idx_str : i + 1]
            #check if this word already be taken by a pattern, if yes, skip, else check
            if new_word in used_word_set:
                continue
            
            char_to_word_map[char] = new_word
            used_word_set.add(new_word)

            # do dfs for it, if found return true, not found, just means this path fail, don't return
            if self.dfsMatch(pattern, idx_pattern + 1, string, i + 1, char_to_word_map, used_word_set):
                return True
            
            # revert last add
            used_word_set.remove(new_word)
            del char_to_word_map[char]
       
        # nothing found
        return False
        

sol = Solution()
pat = "abba"
string = "redbluebluered"
res = sol.wordPatternMatch(pat, string)
print("RESULT: {}".format(res))