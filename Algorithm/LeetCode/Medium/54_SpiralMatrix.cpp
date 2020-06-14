
/*
https://leetcode.com/problems/spiral-matrix/

注意不是正方形  m * n

对于matrix1的模板，每次移动后，压缩上下左右的边界，然后要检查是否越界

*/
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();        
        if(row == 0){
            return vector<int>();
        }
        
        int col = matrix[0].size();     
        if(col == 0){
            return vector<int>(); 
        }
        
        int top = 0, bottom = row - 1;
        int left = 0, right = col - 1;
        
        vector<int> nums;
           
        while(left <= right && top <= bottom){
            // deal with top
            for(int i = left; i <= right; ++i){
                nums.push_back(matrix[top][i]);
            }
            
            if(++top > bottom){
                // move ceiling one level down and check
                break;
            } 

            // deal with right side
            for(int i = top; i <= bottom; ++i){
                nums.push_back(matrix[i][right]);
            }
               
            if(--right < left){
                // move right bound one level left
                break;
            }                   
            
            // bottom
            for(int i = right; i >= left; --i){
                nums.push_back(matrix[bottom][i]);
            }
            if(--bottom < top){
                break;
            }       
            
            for(int i = bottom; i >= top; --i){
                nums.push_back(matrix[i][left]);
            }
            
            if(++left > right){
                break;
            }
     
        }

        return nums;
    }
};