#include <iostream>
using namespace std;

/*
https://leetcode.com/problems/is-subsequence/

2 pointers
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0;
        int tIdx = 0;
        
        int sLen = s.length();
        int tLen = t.length();
        
        while(sIdx < sLen && tIdx < tLen){
            
            if(s[sIdx] == t[tIdx]){
                ++sIdx;
            }
            
            ++tIdx;
        }
        
        if(sIdx == sLen){
            return true;
        }
        
        
        return false;
    }
};