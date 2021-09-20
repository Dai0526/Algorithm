/*
https://leetcode.com/problems/maximum-length-of-repeated-subarray/
DP - same idea of common subsequence
The only difference is it ask for sub array, so
    if A[i] != B[j], we didn't do anything. no min, no max

The max can be can lut[i][j], thus use a variable to rec the max.

*/

#include <vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size();
        int lb = B.size();
        
        vector<vector<int>> lut(la + 1, vector<int>(lb + 1, 0));
        
        
        int maxLen = 0;
        
        for(int i = 1; i < la + 1; ++i){
            for(int j = 1; j < lb + 1; ++j){
                if(A[i - 1] != B[j - 1]){
                    continue;
                }
                lut[i][j] = lut[i - 1][j - 1] + 1;
                maxLen = maxLen < lut[i][j] ? lut[i][j] : maxLen;
            }
        }
        
        return maxLen;
        
    }
};