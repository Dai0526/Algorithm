/*
https://leetcode.com/problems/word-pattern/
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string> tks;
        split(s, tks, ' ');
        
        unordered_map<char, string> patternMap;
        unordered_set<string> visited;
        
        if(pattern.size() != tks.size()){
            return false;
        }
        
        for(int i = 0; i < pattern.size(); ++i){
            char c = pattern[i];
            string str = tks[i];
            
            // pattern(key) not found
            if(patternMap.find(c) == patternMap.end()){
                //check str, return false if already match a pattern
                if(visited.find(str) != visited.end()){
                    return false;
                }
                // add new match
                patternMap[c] = str;
                visited.insert(str);
                continue;
            }
            
            // key exist, then check if pattern match
            if(patternMap[c].compare(str) != 0){
                return false;
            }
        }
        
        return true;
    }
    
    void split(string& s, vector<string>& out, char delim){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delim))
        {
            out.push_back(token);
        }  
    }
    
};