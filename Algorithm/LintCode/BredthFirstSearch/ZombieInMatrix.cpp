/*
598. Zombie in Matrix
https://www.lintcode.com/problem/zombie-in-matrix/
Given a 2D grid, each cell is either a wall 2, a zombie 1 or people 0 (the number zero, one, two).Zombies can turn the nearest people(up/down/left/right) into zombies every day, but can not through wall. How long will it take to turn all people into zombies? Return -1 if can not turn all people into zombies.

Example 1:

Input:
[[0,1,2,0,0],
 [1,0,0,2,1],
 [0,1,0,0,0]]
Output:
2
Example 2:

Input:
[[0,0,0],
 [0,0,0],
 [0,0,1]]
Output:
4
*/


#include <vector>
#include <queue>

using namespace std;
class Solution {


public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    const int DIRS = 4;
    const vector<int> dX = {1, 0, -1, 0}; //r,d,l,up
    const vector<int> dY = {0, 1, 0, -1};
     
    int zombie(vector<vector<int>> &grid) {
        
        int row = grid.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = grid[0].size();
        if(col == 0){
            return 0;
        }
        
        vector<vector<int>> gridCopy(row, vector<int>(col));
        queue<pair<int, int>> myQueue;
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                // copy grid
                gridCopy[i][j] = grid[i][j];
                // push zombine to Queue
                if(grid[i][j] == 1){
                    myQueue.push(pair<int,int>(i,j));
                }
            }
        }
        
        int day = 0;
        //DO BFS for each zombine
        while(!myQueue.empty()){
            ++day;
  
            int qSize = myQueue.size();
            for(int i=0; i<qSize; ++i){
                pair<int, int> curr = myQueue.front();
                myQueue.pop();
            
                int x = curr.first;
                int y = curr.second;
                //cout<<"(x,y) = " << x << ", " << y << endl;
                for(int d = 0; d < DIRS; ++d){
                    int nextX = x + dX[d];
                    int nextY = y + dY[d];
                    
                    
                    if(nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && gridCopy[nextX][nextY] == 0){
                        gridCopy[nextX][nextY] = 1;
                        myQueue.push(pair<int, int>(nextX, nextY));
                    }
                }  
            }   
        }
        
        
        // loop over grid to see if there is still people alive
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(gridCopy[i][j] == 0){
                    return -1;
                }
            }
        }
        
        return day - 1;
        
    }
};