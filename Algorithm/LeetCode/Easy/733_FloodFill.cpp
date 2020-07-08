
/*
https://leetcode.com/problems/flood-fill/
DFS - recursion
    see if it is in range && it is not 0 && !visited
    Then go 4 directions
    
BFS

*/
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
    
private:
    vector<int> dx {1, 0, -1, 0};    
    vector<int> dy {0, 1, 0, -1};
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int row = image.size();
        int col = image[0].size();
        int color = image[sr][sc];

        vector<vector<int>> out(image);
        
        if(color == newColor) { return out; }
        
        queue<pair<int,int>> q; 
        q.push({sr, sc});
        
        while(!q.empty()){
            
            pair<int, int> curr = q.front();
            q.pop();
            
            int r = curr.first;                
            int c = curr.second;
            
            out[r][c] = newColor;
                
            for(int i = 0; i < 4; ++i){
                
                int nextr = r + dy[i];
                int nextc = c + dx[i];
                
                if(nextr < row && nextr >= 0 && nextc < col && nextc >= 0 && out[nextr][nextc] == color){
                    q.push({nextr, nextc});
                } 
            }
        }  
        
        return out;   
    }
};