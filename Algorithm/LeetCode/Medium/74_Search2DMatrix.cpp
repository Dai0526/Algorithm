
/*
https://leetcode.com/problems/search-a-2d-matrix/
By the properties, we can treat it as a 1D sorted array
Do binary search

*/
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // do necessary check, skip due to stay up late and tired
        int row = matrix.size();
        
        if(row == 0){
            return 0;
        }
        
        int col = matrix[0].size();
        
        if(col == 0){
            return 0;
        }
        
        int left = 0;
        int right = row * col - 1;
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
           
            int i = mid / col;
            int j = mid % col;
            
            if(matrix[i][j] < target){
                left = mid;
            }else if(matrix[i][j] > target){
                right = mid;
            }else{
                return true;
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