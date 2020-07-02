/**
 * https://leetcode.com/problems/longest-palindrome/
 */

#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char, int> recs; //char, count
        
        // iterate over string s
        for(char c : s){
            ++recs[c];
        }
        
        int paliLength = 0;
        bool hasOddCount = false;
        for(auto itr = recs.begin(); itr != recs.end(); ++itr){
            int count = itr->second;
            
            paliLength += count / 2 * 2;
            
            if(count % 2 == 1){
                hasOddCount = true;
            }
            
        }
        
        
        return hasOddCount ? paliLength + 1 : paliLength;
        
    }
};