/*
https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/

Two Pointers - sliding window

left ptr is the first apperence of char 1,
right ptr is the last apperence of char 1,

a current ptr i moving to the end step by step,

update left ptr when find a new(3rd) character that s[i] != s[r] && s[i] != s[i - 1]
    len = max(len, i - l)
    l = r + 1 // reset to first apperance of 2nd char

when r when s[i] != s[i - 1]
r = i - 1

*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len = s.length();
        
        //corner case
        if(len < 3){
            return len;
        }
        
        int l = 0;
        int r = -1;
        
        map<char, int> rec;
        int maxlen = numeric_limits<int>::min();
        
        // find the first apperance of diff char
        for(int i = 1; i < len; ++i){
            if(s[i] != s[i-1]){
                r = i - 1; // set right bounry for the first char
                break;
            }
        }

        maxlen = r + 1 - l + 1;
        
        for(int i = r + 2; i < len; ++i){
            if(s[i] == s[i - 1]){
                continue;
            }
            
            // find a char diff than 2nd one
            if(s[i] != s[r]){
                //confim it is not the same as neither of existed 2 chars
                maxlen = max(maxlen, i - l);
                l = r + 1; // update left ptr to the first apperaence of 2nd char
            }
            
            r = i - 1;// update r
        }
        
        return max(maxlen, len - l);   
    }
};