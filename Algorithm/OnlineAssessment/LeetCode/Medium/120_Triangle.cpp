/*
https://leetcode.com/problems/triangle/

Kind of like DP, save min sum for each path when go through each level
Two for loop should be able to solve it

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[0].size();
        
        vector<vector<int>> lut(row, vector<int>(row, 0));
        
        // init top and two side
        lut[0][0] = triangle[0][0];
        
        for(int i = 1; i < row; ++i){
            lut[i][0] = lut[i - 1][0] + triangle[i][0];
            lut[i][i] = lut[i - 1][i - 1] + triangle[i][i];
        }
          
        for(int i = 2; i < row; ++i){
            for(int j = 1; j < i; ++j){
                lut[i][j] = triangle[i][j] + min(lut[i - 1][j], lut[i - 1][j - 1]);
            }
        }   
        
        int min = numeric_limits<int>::max();
        for(int n : lut[row - 1]){
            if(n < min){
                min = n;

            }
        }
        
        return min;
    }
};