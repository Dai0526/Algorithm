/*
https://leetcode.com/problems/design-tic-tac-toe/submissions/

a 2d board - board
1d vec's - row, col for sum
2 int - leftdiag, rightdiag

if player1, +1
if player2, -1

once a value == size, return player -> win


*/
#include <vector>

using namespace std;

class TicTacToe {

private:
    vector<int> rowrec;
    vector<int> colrec;
    int size = 0;
    
    int diagleft = 0;
    int diagright = 0;
    
    vector<vector<int>> board;
    
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board = vector<vector<int>>(n, vector<int>(n, 0));
        rowrec = vector<int>(n, 0);
        colrec = vector<int>(n, 0);
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(board[row][col] != 0){
            return -1;
        }
        
        board[row][col] = player;
        
        int v = player == 1? 1 : -1;
        colrec[col] += v;
        rowrec[row] += v;
        
        if(row == col){
            diagleft += v;
        }
        
        if(row + col == size - 1){
            diagright += v;
        }
        
        if(abs(rowrec[row]) == size || abs(colrec[col]) == size || abs(diagleft) == size || abs(diagright) == size){
            return player;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */