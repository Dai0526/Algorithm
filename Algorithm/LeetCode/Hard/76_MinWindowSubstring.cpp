
/*
Sliding window

*/

#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        
        int sLen = s.length();
        int tLen = t.length();
        
        if(sLen == 0 && tLen == 0){
            return "";
        }
        
        // make map of t - char , count
        unordered_map<char, int> target;  
        for(int i = 0; i < tLen; ++i){
            ++target[t[i]];
        }
                
        unordered_map<char, int> source;
         
        int left = 0;
        int right = 0;
        
        int numTarget = target.size();
        int num = 0;
        
        // min window rec
        int start = 0;
        int end = numeric_limits<int>::max();
        
        while(right < sLen){
            char c = s[right];
                
            if(target.find(c) != target.end()){
                ++source[s[right]]; // update source map
                
                // update result count
                if(target[c] == source[c]){
                    ++num;
                }   
                
                while(num == numTarget && left <= right){
                    if(right - left < end - start){
                        end = right;
                        start = left;
                    }
                    
                    if(target.find(s[left]) != target.end()){
                        if(target[s[left]] == source[s[left]]){
                            --num;
                        }
                        
                        --source[s[left]];
                    }
                    
                    ++left;
                }
                
            }    
            
            ++right;
        }
        
        
        if(end == numeric_limits<int>::max()){
            return "";
        }
        
        return s.substr(start, end - start + 1);
    }
};