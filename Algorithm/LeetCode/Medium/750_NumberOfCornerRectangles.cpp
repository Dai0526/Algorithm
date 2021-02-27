/*
Brute force method, always find 2 points at each row first, then find corresponding column

*/

#include <vector>

using namespace std;

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        
        int r = grid.size();
        
        if(r < 2){
            return 0;
        }
        
        int c = grid[0].size();
        
        if(c < 2){
            return 0;
        }
        
        int count = 0;
        
        for(int i = 0; i < r - 1; ++i){
            for(int j = 0; j < c - 1; ++j){
                
                if(grid[i][j] == 0){
                    continue;
                }
                
                for(int x = j + 1; x < c; ++x){
                    int next = grid[i][x];
                    
                    if(next == 0){
                        continue;
                    }
                    
                    // find second point int the same tow, then scan column to find two 1's
                    for(int y = i + 1; y < r; ++y){
                        if(grid[y][j] == 1 && grid[y][x] == 1){
                            ++count;
                        }    
                    }// find rectangle
                }// find one side
                
            }
        }
        
        return count;
    }
};