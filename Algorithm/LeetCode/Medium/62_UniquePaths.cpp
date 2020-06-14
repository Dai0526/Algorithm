/*
https://leetcode.com/problems/unique-paths/
Math problem, 

1. 递归
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 or n == 1:
            return 1
        return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)
2. DP
Init state
Do it row by row
111111111111111111111
100000000000000000000
100000000000000000000

3. 纯数学
factorial(m + n - 2) // factorial(n - 1) // factorial(m - 1)

*/
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // init a vector with 1's
        vector<vector<int>> board(m, vector<int>(n, 1));
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                
                board[i][j] = board[i - 1][j] + board[i][j - 1];
                
            }
        }
        
        
        return board[m - 1][n - 1];
    }
};