/*
https://leetcode.com/problems/isomorphic-strings/submissions/
s and t have the same length


*/
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;
        
        for(int i = 0; i < s.size(); ++i){
            if(sMap.find(s[i]) == sMap.end()){
                sMap[s[i]] = i;
            }
            
            if(tMap.find(t[i]) == tMap.end()){
                tMap[t[i]] = i;
            }
            
            if(sMap[s[i]] != tMap[t[i]]){
                return false;
            }
            
        }
        
        return true;
    }
    
};