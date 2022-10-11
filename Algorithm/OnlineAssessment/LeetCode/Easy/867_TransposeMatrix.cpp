/*
https://leetcode.com/problems/transpose-matrix/

Idea:
* Direct copy
* in place will be another story


*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> tp(c, vector<int>(r));
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                tp[j][i] = matrix[i][j];
            }
        }
        
        
        return tp;
    }
};