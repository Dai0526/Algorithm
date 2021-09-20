class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        int t = n / 2;
        
        
        int sum = n % 2 == 0 ? 0 : mat[t][t];
        
        for(int i = 0; i < t; ++i){
            sum += mat[i][i] + mat[i][n - 1 - i] + mat[n - 1- i][i] + mat[n - 1- i][n - 1- i]; 
        }
     
        return sum;
    }
};