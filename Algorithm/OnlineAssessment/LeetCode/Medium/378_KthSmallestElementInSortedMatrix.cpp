/*
1  5  9
10 11 13
12 13 15

*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = matrix[0][0];
        int end = matrix[m-1][n-1];
        
        while (start < end) {
            int mid = start + (end - start)/2;
            int cnt = count(matrix, mid);
            if (cnt <k) {
                start = mid +1;
            } else {
                end = mid;
            }
        }
        return end;      
    }
    
    int count(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m - 1;
        int j = 0;
        int count = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                count += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return count;
    }
    
};