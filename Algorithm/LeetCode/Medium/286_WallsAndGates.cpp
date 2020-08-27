/*
https://leetcode.com/problems/walls-and-gates/
Do BFS to mark distance for each stating gate.
*/
#include <vector>
#include <queue>
#include <set>

using namespace std;
class Solution {
private:
    
    vector<int> DIRX {1, 0, -1, 0};
    vector<int> DIRY {0, 1, 0, -1};
    
public:
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        if(row == 0) return;
        
        int col = rooms[0].size();
        if(col == 0) return;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(rooms[i][j] != 0){
                    continue;
                }                
                markDistance(rooms, i, j);
            }
        }
        
    }
    
    void markDistance(vector<vector<int>>& rooms, int r, int c){
        
        int row = rooms.size();
        int col = rooms[0].size();
        
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        
        q.push({r, c});
        visited.insert({r, c});
        int dist = 1;
        
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0; i < qsize; ++i){
                pair<int, int> curr = q.front();
                q.pop();
                
                int y = curr.first;
                int x = curr.second;
                
                for(int d = 0; d < 4; ++d){
                    int nextY = y + DIRY[d];
                    int nextX = x + DIRX[d];

                    // validation - qfa? how about meet a gate
                    if(nextY < 0 || nextY >= row || nextX < 0 || nextX >= col || rooms[nextY][nextX] == -1 || rooms[nextY][nextX] == 0 || visited.find({nextY, nextX}) != visited.end()){
                        continue;
                    }
                    
                    rooms[nextY][nextX] = min(dist, rooms[nextY][nextX]);
                    q.push({nextY, nextX});
                    visited.insert({nextY, nextX});
                }                     
            }
            ++dist;
        }
        
    }
    
};