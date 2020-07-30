/*
https://leetcode.com/problems/palindrome-partitioning/

2. Find all substring combination, then check each substring to see if it is 
    backtracking + plaidrome check
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> comb;
        getSubstringCombination(res, s, 0, comb);
        
        return res;
    }
    
    void getSubstringCombination(vector<vector<string>>& res, string& s, int idx, vector<string>& comb){
        
        if(idx == s.length()){
            res.push_back(comb);
            return;
        }
        
        for(int i = idx; i < s.length(); ++i){
           
            string temp = s.substr(idx, i - idx + 1);
            
            if(isPlaindrome(temp)){
                comb.push_back(temp);
                getSubstringCombination(res, s, i + 1, comb);
                comb.pop_back();
            }
        }
  
    }
    
    
    bool isPlaindrome(const string& s){
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r){
            
            if(s[l] != s[r]){
                return false;
            }
            
            ++l;
            --r;
        }
        
        return true;
    } 
    
};