/*
dp

from memorization to look up table

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        
        vector<int> lut(amount + 1, numeric_limits<int>::max() - 1);
        lut[0] = 0;
        
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(coins[j] > i){
                    continue;
                }
                
                lut[i] = min(lut[i], lut[i - coins[j]] + 1);
            }
        }
        
        return lut[amount] > amount ? -1 : lut[amount];
        
    }   
    
    int coinChange_rec(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        
        // memo
        vector<int> memo(amount + 1, -1);
        int nCoin = exchange(coins, amount, memo);
        return nCoin == numeric_limits<int>::max() ? -1 : nCoin;
    }
    
    
    int exchange(vector<int>& coins, int remain, vector<int>& memo){
        if(remain < 0){
            return numeric_limits<int>::max();
        }
        
        if(memo[remain] != -1){
            return memo[remain];
        }
        
        if(remain == 0){
            return 0;
        }
        
        int ans = numeric_limits<int>::max();
        
        for(int i = 0; i < coins.size(); ++i){
            int n = exchange(coins, remain - coins[i], memo);
            
            if(n != numeric_limits<int>::max()){
                ans = min(ans, 1 + n);
            }
        }
        
        memo[remain] = ans;
        
        return memo[remain];    
    }
    
};