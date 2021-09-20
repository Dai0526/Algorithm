/*
https://leetcode.com/problems/repeated-dna-sequences/
1. Easy solution to use hashset to store all patterns.
2. same idea, but use bit operation to encoding.
*/
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        vector<string> res;
        
        if(s.length() < 11){
            return res;
        }
        
        unordered_map<string, int> patterns;
        
        for(int i = 0; i < s.length() - 9; ++i){
            ++patterns[s.substr(i, 10)];    
        }

        for(unordered_map<string,int>::iterator itr = patterns.begin(); itr != patterns.end(); ++itr){
            if(itr->second > 1){
                res.push_back(itr->first);
            }
        }
                                
        return res;
    }
};