/*
https://leetcode.com/problems/game-of-life/

brute force, go over board and calculate 1 by 1.
* cannot work directly on board, cause it will affect future calculation.

*/


#include <vector>
#include <iostream>
using namespace std;
class Solution {
    
private:
    vector<int> DIRX {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> DIRY {-1, 0, 1, -1, 1, -1, 0, 1};
    
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> copy(board);
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                
                int liveNbhs = 0;
                
                for(int d = 0; d < 8; ++d){
                    
                    int r = i + DIRY[d];
                    int c = j + DIRX[d];
                    
                    if(r >= 0 && r < row && c >= 0 && c < col && copy[r][c] == 1){
                        ++liveNbhs;
                    }
                } 
                
                cout<< "(i,j) = " << i << ", " << j << ", nbhs = " << liveNbhs << endl;
                
                if(copy[i][j] == 1 && (liveNbhs < 2 || liveNbhs > 3)){
                    board[i][j] = 0;
                }
        
                if(copy[i][j] == 0 && liveNbhs == 3){
                    board[i][j] = 1;
                }    
            }
        }
                
    }
};