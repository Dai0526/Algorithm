/*
https://leetcode.com/problems/max-area-of-island/

1. count all connected 1's, mark visited -> a BFS could achieve that
2. a int maxArea for record.

Note that 
        // push all 1's into queue, start from each possible island
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 0 || visited.find({i,j}) != visited.end()){
                    // not an island or already visited
                    continue;
                }
                
                int area = bfs(grid, i, j, visited);
                maxArea = max(maxArea, area);
            }
        }

it will repeated add node when calculate area, e.g.
[
[1,1,0,0,0],
[1,1,0,0,0],
[0,0,0,1,1],
[0,0,0,1,1]
]


(1,1) = 1 will be add by both (0,1) and (1,0,), thus, need another check for visited node.

*/

#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    
private:    
    vector<int> DX {1, 0, -1, 0};
    vector<int> DY {0, 1, 0, -1};
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        
        int col = grid[0].size();
        if(col == 0){
            return 0;
        }
        
        set<pair<int, int>> visited;        
        int maxArea = 0;
        
        // push all 1's into queue, start from each possible island
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == 0 || visited.find({i,j}) != visited.end()){
                    // not an island or already visited
                    continue;
                }
                
                int area = bfs(grid, i, j, visited);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
    
    int bfs(const vector<vector<int>>& grid, int r, int c, set<pair<int, int>>& visited){
        
        int row = grid.size();
        int col = grid[0].size();
        
        queue<pair<int,int>> myQueue;
        myQueue.push({r,c});
        int area = 0;

        while(!myQueue.empty()){
            pair<int,int> root = myQueue.front();
            myQueue.pop();
            
            if(visited.find(root) != visited.end()){
                continue;
            }
            
            visited.insert(root);
            ++area;

            
            for(int d = 0; d < 4; ++d){
                int nextRow = root.first + DY[d] ;
                int nextCol = root.second + DX[d];
                pair<int,int> next(nextRow, nextCol);
                if(nextRow < 0 || nextRow >= row 
                   || nextCol < 0 || nextCol >= col 
                   || visited.find(next) != visited.end() 
                   || grid[nextRow][nextCol] == 0){
                    continue;
                }
                myQueue.push(next);
            }
        }
        return area;
    }
        
};