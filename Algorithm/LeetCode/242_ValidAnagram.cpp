/*
https://leetcode.com/problems/valid-anagram/

store counter for each character in s
then go thourh t to check 

*/


#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        map<char, int> counter;
        for(char c : s){
            if(counter.find(c) == counter.end()){
                counter[c] = 1;
            }else{
                ++counter[c];
            }
        }
        
        // find 
        for(char c : t){
            if(counter.find(c) == counter.end()){
                return false;
            }else{
                --counter[c];
                if(counter[c] == 0){
                    counter.erase(c);
                }
            } 
        }
            
        return true;
    }
};