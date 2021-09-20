/*
https://leetcode.com/problems/surrounded-regions/

BFS - 逆向思维来做

1. Start from each boarder node,  record the position O and mark it as X
2. Then go over board, mark O to X
3. Convert border in the record from X to O

*/

#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
    
private:
    vector<int> DIRX = {1, 0, -1, 0};
    vector<int> DIRY = {0, 1, 0, -1};
    
public:
    void solve(vector<vector<char>>& board) {
        
        int row = board.size();
        
        if(row < 1){
            return;
        }
        
        int col = board[0].size();
        
        if(col < 1){
            return;
        }
        
        queue<pair<int, int>> q;
        
        // push border O queue
        for(int i = 0; i < row; ++i){
            if(board[i][0] == 'O'){
                q.push({i, 0});
            }
            
            if(board[i][col - 1] == 'O'){
                q.push({i, col - 1});
            }
        }
        
        for(int i = 0; i < col; ++i){
            if(board[0][i] == 'O'){
                q.push({0, i});
            }
            
            if(board[row - 1][i] == 'O'){
                q.push({row - 1, i});
            }
        }
        
        // do bfs and use a vector to record border connected O
        vector<pair<int, int>> record;
        set<pair<int, int>> visited;
        
        while(!q.empty()){
            pair<int,int> pr = q.front();
            q.pop();
            
            int r = pr.first;
            int c = pr.second;
            
            // add to record
            record.push_back(pr);            
            // mark to X first
            board[r][c] = 'X';
            // mark visited
            visited.insert(pr);
             
            // check 4 direction
            for(int i = 0; i < 4; ++i){
                int nextR = r + DIRY[i];
                int nextC = c + DIRX[i];
                
                pair<int,int> nextPr(nextR, nextC);
                
                // check if it is valid
                if(nextR >= row - 1 || nextR < 1 || nextC >= col - 1 || nextC < 1 || visited.find(nextPr) != visited.end() || board[nextR][nextC] == 'X'){
                    continue;
                }
                
                q.push(nextPr);
            }  
        }// finish bfs
        
        for(int i = 1; i < row - 1; ++i){
            for(int j = 1; j < col - 1; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        // set board connect O back
        for(const pair<int,int>& p : record){
            board[p.first][p.second] = 'O';
        }
        
    }
};