/*
https://leetcode.com/problems/detect-capital/
    1. If leading Cap,
        True: check rest, if not all Cap, return false
        FALSE: if there is one Cap, return false;

*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length() < 2){
            return true;
        }
        
        bool leadingCap = isCap(word[0]);
        
        if(leadingCap){
            bool restCap = isCap(word[1]);
            for(int i = 2; i < word.length(); ++i){
                if(isCap(word[i]) != restCap){
                    return false;
                }
            }    
        }else{
            // all lower case
            for(int i = 1; i < word.length(); ++i){
                if(isCap(word[i])){
                    return false;
                }
            }    
        }
            
        return true;
    }
    
    bool isCap(char c){
        return c >= 'A' && c <= 'Z' ? true : false;
    }
    
};