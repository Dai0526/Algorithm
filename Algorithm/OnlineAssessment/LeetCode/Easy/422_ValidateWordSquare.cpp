/*
https://leetcode.com/problems/valid-word-square/

Idea:
Get length l
start from (0, 0), (1, 1), ... , (n - 1, n - 1)
Check if row and column are same string


corner cases:
1. row length > column length
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        int l = words.size();
        if(l < 2){
            return true;
        }
        
        for(int i = 0; i < l; ++i){
            
            if(!validateColRow(words, l, i)){
                return false;
            }
        }
        
        return true;
        
    }
    
    bool validateColRow(const vector<string>& target, const int len, int idx){
        
        string strRow = target[idx];
        int rowLen = strRow.length();
        
        if(rowLen > len){
            return false;
        }
        
        for(int i = idx + 1; i < len; ++i){
            char cRow = (i <= rowLen) ? strRow[i] : char('\0');
            char cCol = target[i][idx];
            
            if(cRow != cCol){
                return false;
            }
        }
        
        return true;
        
    }
    
};