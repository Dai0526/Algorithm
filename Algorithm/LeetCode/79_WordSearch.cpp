/*
https://leetcode.com/problems/word-search/solution/
DFS with backtracking...
* 有两个backtracking
    1. 对起始点
    2. 对每一个dfs中点

set<pair<int,int>> visited;

for each cell (i,j) == word[0]
1. add (i,j) to visited
2. do dfs(board, i, j, visited, word, 1)
    return true if found
3. erase (i,j) from visited 


-- dfs
        if(idx == target.length()){
            return true; //找到了
        }     

        For current cell, do 4 direction search
            1. add next cell
            2. do dfs
                if true than return true
            3. pop next cell from visited

*/
#include <vector>
#include <set>
#include <iostream>


using namespace std;

class Solution {
    
private:
    
    const vector<int> DIRX { 1, 0, -1, 0};
    const vector<int> DIRY { 0, 1, 0, -1};

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        if(row == 0){   
            return false;
        }
        
        int col = board[0].size();
        if(col == 0){
            return false;
        }
        
        if(word.length() == 0){
            return false;
        }

        set<pair<int,int>> visited;
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == word[0]){
                    visited.insert({i,j});
                    if(dfs(board, i, j, visited, word, 1)){
                        return true;
                    }
                    visited.erase({i,j});
                }    
            }
        }
        
        return false;
    }
    
    bool dfs(const vector<vector<char>>& grid, int i, int j, set<pair<int,int>>& visited, const string& target, int idx){
        
        int row = grid.size();
        int col = grid[0].size();

        if(idx == target.length()){
            return true;
        }
        
        
        for(int d = 0; d < 4; ++d){
            int newr = i + DIRY[d];
            int newc = j + DIRX[d];
            
            pair<int,int> next(newr, newc);
            
            if(newr < 0 || newr >= row || newc < 0 || newc >= col || visited.find(next) != visited.end() || grid[newr][newc] != target[idx]){
                continue;
            }
            
            visited.insert(next);
            if(dfs(grid, newr, newc, visited, target, idx + 1)){
                return true;
            }
            visited.erase(next);
        }
        
        return false;
    }
};