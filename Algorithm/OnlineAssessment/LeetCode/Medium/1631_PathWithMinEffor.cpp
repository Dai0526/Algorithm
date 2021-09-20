/*
Dijkstra's  - BFS but use priority Queue
*/
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
    
    struct Position{
        int r;
        int c;
        int minMaxEffort;
        
        Position(int row, int col, int maxEff){
            r = row;
            c = col;
            minMaxEffort = maxEff;
        }
    };
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int r = heights.size();
        int c = heights[0].size();
        
        vector<vector<int>> diffs(r, vector<int>(c, numeric_limits<int>::max()));
        
        diffs[0][0] = 0;
        
        auto CompPos = [](Position p1, Position p2) { return p1.minMaxEffort > p2.minMaxEffort; }; 
        priority_queue<Position, vector<Position>, decltype(CompPos)> q(CompPos);
        
        q.push(Position(0, 0, diffs[0][0]));
        
        set<pair<int, int>> visited;
        
        vector<int> ROWDIR { 0, 1, 0, -1};
        vector<int> COLDIR { 1, 0, -1, 0};
        
        while(!q.empty()){
            Position p = q.top();
            q.pop();
            visited.insert({p.r, p.c});
            
            // go 4 directions
            for(int i = 0; i < 4; ++i){
                int x = ROWDIR[i] + p.r;
                int y = COLDIR[i] + p.c;
      
                if(x < 0 || x >= r || y < 0 || y >= c || visited.find({x, y}) != visited.end()){
                    continue; // out of bound, invalid move
                }
                
                
                // update 
                int maxDiff = max(diffs[p.r][p.c], abs(heights[x][y] - heights[p.r][p.c]));
                diffs[x][y] = min(maxDiff, diffs[x][y]);
                q.push(Position(x, y, diffs[x][y]));
            }
            
        }
        
        return diffs[r - 1][c - 1];
    }
};