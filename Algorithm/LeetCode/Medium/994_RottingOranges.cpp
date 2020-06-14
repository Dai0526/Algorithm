/*
https://leetcode.com/problems/rotting-oranges/

QFA: 
1. can I modified directly on grid?
2. Is there only one rotten orange? (bad question)

IDEA
find all rooten orange, push to queue

for each rooten orange, DO a BFS
    mark rooten orange in record for each queue pop
    ++ count


*/

#include <vector>
#include <set>
#include <queue>

using namespace std;

class Solution {

private:
    enum status{
        EMPTY = 0,
        FRESH,
        ROTTEN
    };
    
    vector<int> DIRX {1, 0, -1, 0};
    vector<int> DIRY {0, 1, 0, -1};  
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = grid[0].size();
        if(col == 0){
            return 0;
        }
                
        queue<pair<int,int>> myQueue;
        int fresh = 0;
        for(int i = 0; i< row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == status::ROTTEN){
                    myQueue.push({i,j});
                }
                
                if(grid[i][j] == status::FRESH){
                    ++fresh;
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        set<pair<int,int>> rottenSet;
        int minutes = -1;
        
        while(!myQueue.empty()){
            int qSize = myQueue.size();
            
            for(int n = 0; n < qSize; ++n){
                pair<int,int> curr = myQueue.front();
                rottenSet.insert(curr);
                myQueue.pop();
                
                int r = curr.first;
                int c = curr.second;
                
                for(int i = 0; i < 4; ++i){
                    int newR = r + DIRX[i];
                    int newC = c + DIRY[i];
                    
                    pair<int,int> next(newR, newC);
                    
                    if(rottenSet.find(next) != rottenSet.end() || newR < 0 || newR >= row || newC < 0 || newC >= col || grid[newR][newC] != status::FRESH){
                        continue;
                    }
                    
                    //cout << "New Rotten (x,y) = " << newR << ", " << newC << endl;
                    myQueue.push(next);
                    grid[newR][newC] = status::ROTTEN;
                    --fresh;
                }   
            }
  
            ++minutes;
            //cout<<"minute: " << count << endl;
        }
        
        if(fresh > 0){
            return -1;
        }
        
        
        return minutes;
    }
};