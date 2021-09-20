class Solution {
public:
    bool canWinNim(int n) {
        if(n < 4) return true;
        
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;
        
        for(int i = 3; i <= n; ++i){
           dp[i] = !(dp[i - 1] & dp[i - 2] & dp[i - 3]); 
        }
        return dp[n];
    }

    bool canWinNim_math(int n) {
        return (n % 4) != 0;
    }
};