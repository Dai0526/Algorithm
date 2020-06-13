"""
433. Number of Islands
https://www.lintcode.com/problem/number-of-islands/
Given a boolean 2D matrix, 0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
Find the number of islands.

Example 1:

Input:
[
  [1,1,0,0,0],
  [0,1,0,0,1],
  [0,0,0,1,1],
  [0,0,0,0,0],
  [0,0,0,0,1]
]
Output: 3

Example 2:
Input:
[
  [1,1]
]

Output: 1

"""

"""
a simple bfs to search for all island.

Note that if writting in c++ or Java, for the best practice, 
if grid is passed in by reference, avoid directly modified the grid, 
instead make a copy, or use a hashset to record all visited

"""


from collections import deque

class numberIslands:
    """
    @param grid: a boolean 2D matrix
    @return: an integer
    """
    def numIslands(self, grid):
        #BFS
        if not grid or not grid[0]:
            return 0 
        #               right     up     left     down
        directions = [(1, 0), (0, -1), (-1, 0), (0, 1)]
        total_islands = 0
        visited = set()

        row, col = len(grid), len(grid[0])
        for i in range(row):
            for j in range(col):
                if grid[i][j] == True and (i,j) not in visited:
                    # one island is found, now mark the land it covered
                    self.bfs(grid, i, j, visited, directions)
                    total_islands += 1
                
        return total_islands
        
        
        
    def bfs(self, grid, x, y, visited, directions):
        queue = deque([(x,y)])
        visited.add((x,y))
    
        while queue:
            r, c = queue.popleft()
            
            for dir_x, dir_y in directions:
                next_x = r + dir_x
                next_y = c  + dir_y
                if not self.is_axis_valid(grid, next_x, next_y, visited):
                    continue               
                queue.append((next_x, next_y))
                visited.add((next_x, next_y))
                
    # check in boundry, is not visisted, is island            
    def is_axis_valid(self, grid, x, y, visited):
        if (x, y) in visited:
            return False
        
        row, col = len(grid), len(grid[0])
            
        if not (0 <= x < row and 0 <= y < col):
            return False
        
        return grid[x][y]