/*
https://leetcode.com/problems/set-matrix-zeroes/
init 2 set
one for row, one for col

iterate matrix, mark 0 col and 0 row
reconstruc matrix by iterating matrix again

actuallt we can do it in Place!
mark col or row 0 by set the first element to zero, then do resonctrution.
e.g.

if matrix[i][j] == 0 
then matrix[0][j] = 0 and matrix[i][0] = 0

There is a corner, how to deal with first row and first column?

[[0,1,2,0],
[3,4,5,2],
[1,3,1,5]]

so, mark if first row and first col need to be set to zero,
after set middle part

set first col and set first row

*/
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) { return; }
        
        int col = matrix[0].size();
        if(col == 0) { return; }
        
        
        // check first row need change
        bool isFstRow = false;
        for(int j = 0; j < col; ++j){
            if(matrix[0][j] == 0){
                isFstRow = true;
                break;
            }
        }
  
        bool isFstCol = false;
        for(int i = 0; i < row; ++i){
            if(matrix[i][0] == 0){
                isFstCol = true;
                break;
            }
        }        
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
            
        // re-construction
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(isFstCol){
            for(int i = 0; i < row; ++i){
                matrix[i][0] = 0;
            }
        }
     
        if(isFstRow){
            for(int j = 0; j < col; ++j){
                matrix[0][j] = 0;
            }
        }
        
    }
};