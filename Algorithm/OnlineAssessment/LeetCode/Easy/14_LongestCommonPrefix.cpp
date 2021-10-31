/*
Brute Force Solution
https://leetcode.com/problems/longest-common-prefix/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        
        string prefix = "";
        
        for(int i = 0; i < strs[0].length(); ++i){
            for(int j = 0; j < strs.size(); ++j){
                
                if(i >= strs[j].length()){
                    return prefix;
                }
                
                if(strs[j][i] != strs[0][i]){
                    return prefix;
                }
            }
            
            prefix += strs[0][i];
        }
        
        return prefix;
    }
};