/*
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

Start from right top corner

if negative, count += nRow - idx, then move left
if positive, go down

*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        
        int col = grid[0].size();
        if(col == 0) return 0;
        
        int count = 0;
        int r = 0;
        int c = col - 1;
        
        while(r < row && c >=0){
            if(grid[r][c] < 0){ 
                count += row - r;
                --c;
            }else{                 
                ++r; 
            }
        }
        
        return count;
    }
};