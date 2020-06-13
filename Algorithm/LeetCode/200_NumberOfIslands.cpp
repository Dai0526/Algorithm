/*
https://leetcode.com/problems/number-of-islands/
1. Use bfs
    For each node
        if never visited, and it is a island
            Do BFS to mark all connect island as visited

    When Do BFS, check valid point and push to queue

*/

#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
    
private:
    vector<int> DIRX {1, 0, -1, 0};
    vector<int> DIRY {0, 1, 0, -1}; 
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = grid[0].size();
        
        if(col == 0){
            return 0;
        }
        
        int nIsland = 0;
        vector<vector<char>> workingGrid(grid);
        set<pair<int, int>> visited;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                // do BFS to mark connected island
                pair<int,int> p(i,j);
                
                if(visited.find(p) == visited.end() && workingGrid[i][j] == '1'){
                    MarkAllConnected(workingGrid, p, visited);
                    ++nIsland; 
                }
            }    
        }
        
        return nIsland;
    }
    
    void MarkAllConnected(vector<vector<char>>& grid, const pair<int,int>& p, set<pair<int,int>>& visited){

        queue<pair<int,int>> myQueue;
        myQueue.push(p);
        visited.insert(p);
        
        while(!myQueue.empty()){
            pair<int,int> curr = myQueue.front();
            myQueue.pop();
            
            int r = curr.first;
            int c = curr.second;

            for(int i = 0; i < 4; ++i){
                int newRow = r + DIRX[i];
                int newCol = c + DIRY[i];
                
                pair<int,int> next(newRow, newCol);
                
                if(visited.find(next) != visited.end() || newCol < 0 || newCol >= grid[0].size() || newRow < 0 || newRow >= grid.size() || grid[newRow][newCol] == '0'){
                    continue;
                }
                
                myQueue.push(next);
                visited.insert(next);
            }
            
        }
        
    }
};