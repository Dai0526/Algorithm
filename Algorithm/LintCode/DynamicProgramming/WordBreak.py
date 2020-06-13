class Solution:
    """
    @param: s: A string
    @param: dict: A dictionary of words dict
    @return: A boolean
    """
    def wordBreak(self, s, dict):
        if len(s) == 0:
            return True
        
        return self.dp(s, dict)
        
    def dfs(self, start, s, dict):
        size = len(s)
        
        if start == size:
            return True
        
        # go over dict to find match
        for word in dict:
            
            if s[start:].startswith(word):
                word_len = len(word)
                if self.dfs(start + word_len, s, dict):
                    return True
        
        #if not found
        return False    
        
    """
    Same idea as WordBreak3, it can be simplified. by just finding one solution
    """
    def dp(self, s, dict):

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

        for i in range(str_size):
            for j in range(i, str_size):
                for k in range(i, j):
                    lut[i][j] += lut[i][k] * lut[k+1][j]


        return lut[0][str_size - 1] > 0
            