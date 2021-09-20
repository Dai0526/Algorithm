/*
https://leetcode.com/problems/maximal-square/
brute force, iterate each cell, 

go "down-right"


follow-up: how to do it by using dp

 (i - 1,j - 1) | (i - 1, j)
 (i, j - 1)    | (i, j) 
For each '1', do a analysis
First observation, when all other 3 cells are the same value, (i,j) will be val + 1
Second observation, (i,j) is min val + 1

Method: 
1. create a same size look up table lut,

2. Init first row and col, update corresponding value.
    If it is 1, then update max len to 1.

So transfer function is
lut(i,j) = min( lut(i-1, j-1), lut(i-1, j), lut(i, j-1)) + 1

and update max len;

*/
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = matrix[0].size();
        
        if(col == 0){
            return 0;
        }
        
        int maxLen = 0;
        vector<vector<int>> lut(row, vector<int>(col, 0));
        //init lut
        for(int i = 0; i < row; ++i){
            lut[i][0] = matrix[i][0] - '0';
            
            if(lut[i][0] == 1){
                maxLen = 1;
            }
        }
        
        for(int j = 0; j < col; ++j){
            lut[0][j] = matrix[0][j] - '0';
            if(lut[0][j] == 1){
                maxLen = 1;
            }
        }
        
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                
                lut[i][j] = matrix[i][j] - '0';
                
                if(matrix[i][j] == '0'){
                    continue;
                }
                
                lut[i][j] = min(min(lut[i - 1][j - 1], lut[i - 1][j]), lut[i][j-1]) + 1;
                maxLen = maxLen < lut[i][j] ? lut[i][j] : maxLen;
            }
        }
        
        return maxLen * maxLen;
    }
    
    int maximalSquare_slow(vector<vector<char>>& matrix) {
        int row = matrix.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = matrix[0].size();
        
        if(col == 0){
            return 0;
        }
        
        int maxLen = 0;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                
                if(matrix[i][j] == '0'){
                    continue;
                }
                
                int len = 1;
                bool isValid = true;
                while((j + len) < col && (i + len) < row){
                    // check new col
                    for(int m = j; m <= j + len; ++m){
                        if(matrix[i + len][m] == '0'){
                            isValid = false;
                            break;
                        }
                    }
                    
                    if(!isValid){
                        break;
                    }
                    
                    for(int n = i; n <= i + len; ++n){                         
                        if(matrix[n][j + len] == '0'){
                            isValid = false;
                            break;
                        }
                    }
                    
                    
                    if(isValid){
                        ++len;
                    }else{     
                        break;
                    }
                }
                
                maxLen = maxLen < len ? len : maxLen;
                
            }
        }
     
        return maxLen * maxLen;
    }
};