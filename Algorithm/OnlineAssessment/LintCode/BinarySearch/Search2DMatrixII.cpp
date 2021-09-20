/*
38. Search a 2D Matrix II
https://www.lintcode.com/problem/search-a-2d-matrix-ii
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.

This matrix has the following properties:

Integers in each row are sorted from left to right.
Integers in each column are sorted from up to bottom.
No duplicate integers in each row or column.


Example 1:
Input:
	[[3,4]]
	target=3
Output:1

Example 2:
Input:
    [
      [1, 3, 5, 7],
      [2, 4, 7, 8],
      [3, 5, 9, 10]
    ]
    target = 3
Output:2
Challenge

O(m+n) time and O(1) extra space

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int i = 0;
        int j = col - 1;
        
        int count = 0;
        
        while(i < row && j >= 0){
            if(matrix[i][j] == target){
                ++count;
            }
            
            if(matrix[i][j] > target){
                --j;
            }else{
                ++i;
            }
        }
        
        return count;
    
    }
};