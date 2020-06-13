/*
https://leetcode.com/problems/longest-palindromic-substring/

QFA: 
1. case sensitive?
2. number? character? contain special character? ignore?
3. ab, return a or return b?

IDEA

for each character c, need 2 checks
1. c is the center
2. c and its next c2 as center

need string and minSize for record

*/
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        int sLen = s.length();
        
        if(sLen == 0){
            return "";
        }
        
        if(sLen == 1){
            return s;
        }
        
        std::pair<int,int> idx{0,0};
        
        for(int i = 0; i < sLen - 1; ++i){
            GetPalindrome(i, i, idx, s);                  
            GetPalindrome(i, i + 1, idx, s); 
        }
        
        return s.substr(idx.first, idx.second - idx.first + 1);
        
    }
    
    void GetPalindrome(int left, int right, pair<int,int>& rec, const string& s){
        int maxSize = rec.second - rec.first;
        int strLen = s.length();
        
        while(left >= 0 && right < strLen){
            
            if(s[left] != s[right]){
                break;
            }
            
            --left;
            ++right;  
        }
        
        ++left;
        --right;
        
        if(right - left > maxSize){
            rec.first = left;
            rec.second = right;
        }
    }
    
};