/*
https://leetcode.com/problems/perfect-squares/
DP problem

dp[i] := ans
dp[0] = 0
dp[i] = min{dp[i – j * j] + 1} 1 <= j * j <= i

也可以用数学方式求解，一个数最多有4个平方和
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> lut(n + 1, numeric_limits<int>::max());
        
        // init
        lut[0] = 0;
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j * j <= i; ++j){
                lut[i] = min(lut[i], lut[i - j * j] + 1);
            }
        }
        
        return lut[n];
    }
};