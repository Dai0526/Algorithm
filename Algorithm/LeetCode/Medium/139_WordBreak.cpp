/*
https://leetcode.com/problems/word-break/
*/

class Solution {
public:
    
    // dp solution
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> lut(s.length() + 1, false);
        
        // init
        lut[0] = true;
        
        for(int i = 1; i <= s.length(); ++i){
            for(int j = 0; j < i; ++j){
                
                // find a substring which is valid, and check
                // leftover part is in the dictionary
                if(lut[j] == false){
                    continue;
                }
                
                string target = s.substr(j, i - j);
        
                if(words.find(target) != words.end()){
                    lut[i] = true;
                    break;
                }
            }
        }
        
        return lut[s.length()];
    }
    
    bool wordBreak_dfs(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> record(s.length(), -1);
        
        return dfs(s, words, 0, record);
        
    }
    
    bool dfs(string s, unordered_set<string> words, int idx, vector<int>& visited){
        if(idx == s.length()){
            return true;
        }
        
        if(visited[idx] != -1){
            // already visited
            return visited[idx] == 1;
        }
        
        for(int end = idx + 1; end <= s.length(); ++end){
            string target = s.substr(idx, end - idx);
            if(words.find(target) == words.end()){
                continue;
            }
            
            if(dfs(s, words, end, visited)){
                visited[idx] = 1;
                return true;
            }
        }
        
        visited[idx] = 0;
        return false;
    }
};