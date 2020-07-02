
/*
brute force recursion

idea like two pointer
left = s[0], right = s[l - 1]

if equal:
    ++left
    --left
if not equal
    max(lps(++left, right), lps(left, --right))

*Save cases with memo,
instead of return, record it in a 2d vec left,right = value,


DP SOLUTION.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        if(l == 0){
            return 0;
        }
        
        vector<vector<int>> memo(l, vector<int>(l, 0));
        
        return helper(0, l - 1, s, memo);
    }
    
    int helper(int left, int right, const string 
               & s, vector<vector<int>>& memo){
        // recursion exit
        if(left == right){
            return 1;
        }
        
        if(left > right){
            return 0;
        }
        
        if(memo[left][right] != 0){
            return memo[left][right];
        }
        
        if(s[left]==s[right]){
            memo[left][right] = 2 + helper(left + 1, right - 1, s, memo);
        }else{
            memo[left][right] = max(helper(left + 1, right, s, memo),                                           helper(left, right - 1, s, memo)); 
           
        }
        
        return memo[left][right];
    }
};