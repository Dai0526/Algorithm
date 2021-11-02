/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/

class Solution {

public:
    vector<int> DIRX { -1, 1, -1, 0, 1, -1, 0, 1 };
    vector<int> DIRY { -1, 1, 0, 1, -1, 1, -1, 0 };
    
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n < 1){
            return -1;
        }
        
        if(grid[0][0] != 0 || grid[n - 1][n - 1] != 0){
            return -1;
        }
        
        queue<pair<int,int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        
        int dest = n - 1;
        
        while(!q.empty()){
            
            pair<int, int> curr = q.front();
            q.pop();
            
            int r = curr.first;
            int c = curr.second;
            int dist = grid[r][c];

            if(r == dest && c == dest){
                return dist;
            }
            
            for(int i = 0; i < 8; ++i){
                int nextR = r + DIRY[i];
                int nextC = c + DIRX[i];
                
                if(nextR < 0 || nextR >= n || nextC < 0 || nextC >= n){
                    continue;
                }
                
                // push to queue only when nodes are upated as min
                if(grid[nextR][nextC] == 0){
                    grid[nextR][nextC] = dist + 1;
                    q.push({nextR, nextC});
                }else{
                    int temp = grid[nextR][nextC];
                    grid[nextR][nextC] = min(dist + 1, temp);
                
                    if(temp != grid[nextR][nextC]){
                        q.push({nextR, nextC});
                    }
                }
            }
        }
        
        return -1;
    }
};