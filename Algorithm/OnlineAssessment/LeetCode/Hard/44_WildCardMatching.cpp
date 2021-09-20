/*
https://leetcode.com/problems/wildcard-matching/submissions/
DP

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchHelper(s, p);
    }
    
    bool isMatchHelper(string& s, string& p){
        int sLen = s.size();
        int pLen = p.size();
        
        vector<vector<bool>> lut(sLen + 1, vector<bool>(pLen + 1, false));
        
        //init - empty s and p can match
        lut[0][0] = true;
        
        //init - if s is empty, it is true if p is continous *
        for(int i = 1; i <= pLen; ++i){
            if(p[i - 1] == '*'){
                lut[0][i] = lut[0][i - 1];
            }
        }
        
        for(int i = 1; i <= sLen;  ++i){
            for(int j = 1; j <= pLen; ++j){             
                if(p[j - 1] == '*'){
                    lut[i][j] = lut[i - 1][j] || lut[i][j - 1];
                }else{
                    
                    if(lut[i - 1][j - 1]  == false) continue;

                    if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                        lut[i][j] = true;
                    }
                      
                }        
            }
        }
        
        return lut[sLen][pLen];
    }
    
};