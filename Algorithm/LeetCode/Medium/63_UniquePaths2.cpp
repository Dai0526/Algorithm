/*
https://leetcode.com/problems/unique-paths-ii/

same idea - DP

*/
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if(row == 0){
            return 0;
        }
        
        int col = obstacleGrid[0].size();
        if(col == 0){
            return 0;
        }
        
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        
        vector<vector<int>> grid(obstacleGrid);
        grid[0][0] = 1;    
        
        //Init
        for(int i = 1; i < row; ++i){
            grid[i][0] = obstacleGrid[i][0] == 1 || grid[i-1][0] == 0 ? 0 : 1;
        }
        
        for(int j = 1; j < col; ++j){
            grid[0][j] = obstacleGrid[0][j] == 1 || grid[0][j - 1] == 0 ? 0 : 1;
        }
        
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){                
                grid[i][j] = grid[i][j] == 1 ? 0 : grid[i-1][j] + grid[i][j-1];              
            }
        }
        
        return grid[row-1][col-1];
    }
};