/*
DFS
https://leetcode.com/problems/n-queens/
1. A func to check if this move is valid
2. dfs(int n, vector<int> board,vector<vector<string>> res)
    
    vector<int> board - size = n, each item is the column number of queen.
自然而然的解题
    1. 想一个function, 用来判断当前点是否会被之前的Queen Attack
    2. 输入过程皆为list方便控制，那之后一定有一个function把list of list变为输出想要的格式
    3. 之后就是普通的dfs 
        #递归的想法是 遍历棋盘上每一个row
        #递归的退出 如果棋盘走到了最后一个row，说明满足条件，return

        # 对于每一个row，
        # 对于每一个col， push in board, 做dfs, pop out 

*/
#include <vector>
#include <iostream>

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queens;
        
        dfs(n, queens, res);
        
        return res;        
    }
    
    void dfs(int n, vector<int>& queens, vector<vector<string>>& out){
        if(n == queens.size()){
            out.push_back(makeBoard(queens));
            return;
        }
        
        int row = queens.size();
        
        for(int col = 0; col < n; ++col){
            if(!isValid(col, row, queens)){
                continue;
            }
            
            queens.push_back(col);
            dfs(n, queens, out);
            queens.pop_back();
            
        }   
    }
    
    bool isValid(int col, int row, const vector<int>& queens){
        for(int i = 0; i < queens.size(); ++i){
            int j = queens[i];
            if(col == j || row == i || abs(j - col) == abs(i - row)){
                return false;
            }
        }
         
        return true;
    }
    
    vector<string> makeBoard(const vector<int>& queens){
        vector<string> bd;
        int nq = queens.size();
        for(int i = 0; i < nq; ++i){
            string temp = "";
            int col = queens[i];
            for(int j = 0; j < nq; ++j){
                if(j == col){
                    temp += "Q";
                }else{
                    temp += ".";
                }
            }
            bd.push_back(temp);
        }
        
        return bd;
    }
    
};