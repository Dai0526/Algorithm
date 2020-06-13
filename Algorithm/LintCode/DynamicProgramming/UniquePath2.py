
"""
115. Unique Paths II
https://www.lintcode.com/problem/unique-paths-ii/

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example 1:
	Input: [[0]] Output: 1

Example 2:
	Input:  [[0,0,0],[0,1,0],[0,0,0]] Output: 2	
	Explanation:
	Only 2 different path.
	
Notice
m and n will be at most 100.


动态规划

初始化
    如果在grid中无阻拦
        lut[0][j] = 1 and lut[i][0] = 1
    若有阻拦，
        则设为0，且之后的都设为0

Transfer function
obs[i][j] == 0 ? lut[i][j] = lut[i-1][j] + lut[i][j-1] : 0

"""

class Solution:
    """
    @param obstacleGrid: A list of lists of integers
    @return: An integer
    """
    def uniquePathsWithObstacles(self, obstacleGrid):
        # write your code here
        row = len(obstacleGrid)
        if row == 0:
            return 0
        col = len(obstacleGrid[0])
        if col == 0:
            return 0
        
        #init dp condition
        lut = [[0 for j in range(col)] for i in range(row)]
        
        for i in range(row):
            if obstacleGrid[i][0] == 1:
                break
            lut[i][0] = 1
            
        for j in range(col):
            if obstacleGrid[0][j] == 1:
                break
            lut[0][j] = 1
        
        for i in range(1, row):
            for j in  range(1, col):
                if obstacleGrid[i][j] == 1:
                    lut[i][j] = 0
                else:
                    lut[i][j] = lut[i - 1][j] + lut[i][j - 1]
        
        return lut[row - 1][col - 1] 

test = Solution()
grid = [[0,0],[0,0],[0,0],[1,0],[0,0]]
nPpath = test.uniquePathsWithObstacles(grid)
print(nPpath)