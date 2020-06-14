/*
DP

Transfer function :
grid[i][j] += min(grid[i-1][j], grid[i][j-1])

可以继续优化空间 1D的lut

因为每次只要知道当前 左边和上边
左边有grid初始当前vector提供，上边由vector记录的之前结果来记录


*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int row = grid.size();
        if(row == 0) return 0;
        
        int col = grid[0].size();
        if(col == 0) return 0;
        
        vector<vector<int>> lut(grid);
        
        // init
        for(int i = 1; i < row; ++i){
            lut[i][0] += lut[i - 1][0];
        }
        
        for(int j = 1; j < col; ++j){
            lut[0][j] += lut[0][j - 1];
        }
        
        // do dp
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                lut[i][j] += min(lut[i][j - 1], lut[i - 1][j]);
            }
        }
        
        return lut[row - 1][col - 1];
    }


    int minPathSum1D(vector<vector<int>>& grid) {
        int row = grid.size(); 
        if(row == 0) return 0;
        
        int col = grid[0].size();
        if(col == 0) return 0;
        
        vector<int> lut(col, grid[0][0]);
        
        for (int j = 1; j < col; ++j)
            lut[j] = lut[j - 1] + grid[0][j]; 
        
        for (int i = 1; i < row; ++i) {
            lut[0] += grid[i][0]; 
            for (int j = 1; j < col; j++)
                lut[j] = min(lut[j - 1], lut[j]) + grid[i][j];
        }

        return lut[col - 1];
    
    }
};