/*
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
	Input:  [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
],3
	Output: true
	
	Explanation: 
	return true if included.
Challenge
O(log(n) + log(m)) time
*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        if(row == 0){
            return false;
        }
        
        int col = matrix[0].size();
        if(col == 0){
            return false;
        }
        
        int left = 0;
        int right = row * col - 1;
        
        while(left + 1 < right){
            
            int mid = left + (right - left) / 2;
            
            int i = mid / col;
            int j = mid % col;
            
            if(matrix[i][j] < target){
                left = mid;
            }else{
                right = mid;
            }
        }
        
        if(matrix[left / col][left % col] == target){
            return true;
        }
        
        if(matrix[right / col][right % col] == target){
            return true;
        }
        
        return false;
        
    }
};