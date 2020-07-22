"""
33. N-Queens
https://www.lintcode.com/problem/n-queens/
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other(Any two queens can't be in the same row, column, diagonal line).
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' each indicate a queen and an empty space respectively.


Example 1:

Input: 1
Output:
   [["Q"]]


Example 2:
Input:4
Output:
[
  // Solution 1
  [".Q..",
   "...Q",
   "Q...",
   "..Q."
  ],
  // Solution 2
  ["..Q.",
   "Q...",
   "...Q",
   ".Q.."
  ]
]

Challenge
Can you do it without recursion?

"""

class NQueen:
    """
    @param: n: The number of queens
    @return: All distinct solutions
    """

    def solveNQueens(self, n):
        # write your code here
        result = []  
        self.dfs(n, [], result)
        return result

    """
    自然而然的解题
    1. 想一个function, 用来判断当前点是否会被之前的Queen Attack
    2. 输入过程皆为list方便控制，那之后一定有一个function把list of list变为输出想要的格式
    3. 之后就是普通的dfs 
        #递归的想法是 遍历棋盘上每一个row
        #递归的退出 如果棋盘走到了最后一个row，说明满足条件，return

        # 对于每一个row，
        # 对于每一个col， push in board, 做dfs, pop out

    """
        
    def dfs(self, n, permutation, result):
        if n == len(permutation):
            result.append(self.make_board(permutation))
            return
        
        row = len(permutation)
        for col in range(n):
            #print("size = {}, row = {}, col = {}, and valid {}".format(len(permutation), row, col,self.isValid(col, row, queens)))
            #print("Queens: {}\r\n".format(queens))
            if not self.isValid(col, row, permutation):
                continue
            
            permutation.append(col)
            self.dfs(n, permutation, result)
            permutation.pop()
         
            
            
        
    # check if there is any queen in board will attack each other   
    def isValid(self, c, r, queen_rec):
        
        for y in range(len(queen_rec)):
            x = queen_rec[y]
            if y < 0 :
                continue
            if c == x or r == y or abs(x - c) == abs(y - r):
                return False
        return True
        
    def make_board(self, permutation):
        board = []
        n = len(permutation)
        for i in range(n):
            col = permutation[i]
            row_str = ''
            for j in range(n):

                if j == col:
                    row_str += 'Q'
                else:
                    row_str += '.'
            board.append(row_str)       
        return board

                

n_queen = NQueen()
permutation = [2]

#res = n_queen.isValid(1,2,permutation)

#res = n_queen.make_board(permutation)
res = n_queen.solveNQueens(4)

print(res)