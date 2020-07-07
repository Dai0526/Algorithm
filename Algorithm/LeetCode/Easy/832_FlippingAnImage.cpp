/*
https://leetcode.com/problems/flipping-an-image/submissions/
Simple reverse and inverse operation
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        vector<vector<int>> img(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                img[i][j] = A[i][col - 1 - j] == 1 ? 0 : 1; // binary matrix, if 0, inverse 1; if 1 inverse 0.
            }
        }
        
        return img;
        
    }
};