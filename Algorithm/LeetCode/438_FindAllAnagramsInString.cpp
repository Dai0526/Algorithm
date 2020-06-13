/*
QFA:  1.only alph? if only alph we can use array[26] for it

1. IDEA
maintain two hashmap, 1 for counter of char in P

one as a sliding window's counter in S, then compare two map for each move

*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        
        if(sLen < pLen){
            return vector<int>();
        }
        
        
        // set up map
        map<char, int> pCounter;
        
        for(char c : p){
            if(pCounter.find(c) == pCounter.end()){
                pCounter[c] = 1;
            }else{
                ++pCounter[c];
            }
        }
        
        // check s
        map<char, int> sCounter;
        vector<int> idxs;
        
        int windowSize = 0;
        
        for(int i = 0; i < sLen; ++i){

            char c1 = s[i];
            
            //add right
            if(sCounter.find(c1) == sCounter.end()){
                sCounter[c1] = 1;
            }else{
                ++sCounter[c1];
            }
            
            ++windowSize;
            
            // erase left when window is filled
            if(windowSize > pLen){
                char c2 = s[i - pLen];
                
                if(sCounter[c2] == 1){
                    sCounter.erase(c2);
                }else{
                    --sCounter[c2];
                }
                
                --windowSize;
            }
            
            
            // compare 2 map after sliding windows
            if(pCounter == sCounter){
                idxs.push_back(i - pLen + 1);
            }
        }
        
        return idxs;
    }
};