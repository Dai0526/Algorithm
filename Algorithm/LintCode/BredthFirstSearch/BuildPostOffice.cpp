/*
573. Build Post Office II
https://www.lintcode.com/problem/build-post-office-ii
Given a 2D grid, each cell is either a wall 2, an house 1 or empty 0 (the number zero, one, two), find a place to build a post office so that the sum of the distance from the post office to all the houses is smallest.

Return the smallest sum of distance. Return -1 if it is not possible.

Example
Example 1:

Input：[[0,1,0,0,0],[1,0,0,2,1],[0,1,0,0,0]]
Output：8
Explanation： Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Example 2:

Input：[[0,1,0],[1,0,1],[0,1,0]]
Output：4
Explanation： Placing a post office at (1,1), the distance that post office to all the house sum is smallest.
Notice
You cannot pass through wall and house, but can pass through empty.
You only build post office on an empty.


对每个house做bfs, 累计空格能到达house的数量已经步数，
最后做一个统计
*/


#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;



class Solution {
public:
    /**
     * @param grid: a 2D grid
     * @return: An integer
     */
    
    const vector<int> dX = {1, 0, -1, 0};  
    const vector<int> dY = {0, 1, 0, -1}; 
     
    struct Point{
        public:
        
            int x;
            int y;
            int nHouses;
            int dist;
        
            Point(){
                nHouses = 0;
                dist = 0;
                x = 0;
                y = 0;
            }
        
            Point(int r, int c):x(r),y(c){
                nHouses = 0;
                dist = 0;
            }
    }; 
     
    int shortestDistance(vector<vector<int>> &grid) {
        
        int row = grid.size();
        if(row == 0){
            return -1;
        }
        
        int col = grid[0].size();
        if(col == 0){
            return -1;
        }
    
        set<pair<int,int>> houses;
        
        vector<vector<Point>> points(row, vector<Point>(col));
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 1){
                    houses.insert(pair<int,int>(i,j));
                }
                
                Point p(i,j);
                points[i][j] = p;
            }
        }
        
        int numHouse = houses.size();
        
        // do BFS for each house
        for(pair<int,int> house : houses){
            
            queue<pair<int,int>> myQueue;
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            
            myQueue.push(house);
            visited[house.first][house.second] = true;
            int nStep = 0;
            while(!myQueue.empty()){
                int qSize = myQueue.size();
                ++nStep;
                for(int i = 0; i < qSize; ++i){
                    pair<int, int> curr = myQueue.front();
                    myQueue.pop();
                    
                    for(int d = 0; d < 4; ++d){
                        int nextX = curr.first + dX[d];
                        int nextY = curr.second + dY[d];
           
                        if(isValid(nextX, nextY, row, col, grid) && visited[nextX][nextY] == false){
                            
                            points[nextX][nextY].nHouses += 1;
                            points[nextX][nextY].dist += nStep;
                            myQueue.push(pair<int,int>(nextX, nextY));
                            visited[nextX][nextY] = true;
                        }
                        

                    }
                }
                
            }
        }
        
        
        // After BFS, find the smallest distant which number of house is the same as houses
        int minStep = numeric_limits<int>::max();
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 0 && points[i][j].nHouses == numHouse){
                    minStep = min(minStep, points[i][j].dist);    
                }
            }
        }
        
        if(minStep == numeric_limits<int>::max()){
            return -1; // not all connected,no such postoffice
        }
        
        return minStep;
        
    }
    
    
    bool isValid(int x, int y, int row, int col, vector<vector<int>> &grid){
        
        if(x >=0 && x < row && y >=0 && y<col && grid[x][y] == 0){
            return true;
        }
        
        return false;
    }
    
};