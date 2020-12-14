/*
https://leetcode.com/problems/burst-balloons/

DP solutions - divided and conqur to left and right problems, and keep
update the best answer for it.

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> extNum(n + 2);
        
        std::copy(nums.begin(), nums.end(), extNum.begin() + 1);
        
        extNum[0] = 1;
        extNum[n + 1] = 1;
        
        vector<vector<int>> lut(n + 2, vector<int>(n + 2, 0));
        
        for(int l = n; l > -1; --l){
            for(int r = l + 2; r < n + 2; ++r){
                for(int i = l + 1; i < r; ++i){
                    lut[l][r] = max(lut[l][r], extNum[l] * extNum[i] * extNum[r] + lut[l][i] + lut[i][r]);
                }
            }
        }
        
        
        return lut[0][n + 1];
    }
};