/*
https://leetcode.com/problems/one-edit-distance/

Always iterate both string with smaller size times,

if find one diff
    if size equal, return compare rest string
    if not equal, return compare rest shorter with rest + 1 longer stirng

if all same, the check if l1 - l2 == 1

*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string& s, string& t) {
        
        int slen = s.length();
        int tlen = t.length();
        
        if(slen > tlen){
            return isOneEditDistance(t, s);
        }
        
        if(tlen - slen > 2){
            return false;
        }
        
        for(int i = 0; i < slen; ++i){
            // only handle unequal cases
            if(s[i] == t[i]){
                continue;
            }
            
            if(slen == tlen){
                return strcmp(&t[i + 1], &s[i + 1]) == 0;
            }else{
                return strcmp(&t[i + 1], &s[i]) == 0;
            }  
        }
        
        return tlen == (slen + 1);
    }
};