"""
28. Search a 2D Matrix
https://www.lintcode.com/problem/search-a-2d-matrix/
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example 1:
	Input:  [[5]],2
	Output: false
	
	Explanation: 
	false if not included.
	
Example 2:
	Input:  
    [[1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]],3
	Output: true
	
	Explanation: 
	return true if included.
Challenge
O(log(n) + log(m)) time

It is soted array but divied into row segment

1. do a binary search for the m[i][col - 1] to find which row it is located
2. do a binary search for the m[a][j] to find the answer

"""

class Solution:
    """
    @param matrix: matrix, a list of lists of integers
    @param target: An integer
    @return: a boolean, indicate whether matrix contains target
    """
    def searchMatrix(self, matrix, target):
        row = len(matrix)
        if row == 0:
            return False
        
        col = len(matrix[0])
        if col == 0:
            return False
            

        # do binary search
        left, right = 0, col * row - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            
            i = mid // col
            j = mid % col
            
            if matrix[i][j] < target:
                left = mid
            else:
                right = mid

        if matrix[right // col][right % col] == target:
            return True    
            
        if matrix[left // col][left % col] == target:
            return True
            
        return False
         