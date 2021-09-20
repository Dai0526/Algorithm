/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
DP solution

init: 
day 1  ->  profit[0] = -price[0]; min_price = price[0]

Transition function - find max profit between prvious day and today
profit[i] = max(profit[i - 1], prices[i] - minPrice);

*/

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        
        vector<int> profit(n, 0);
        int minPrice = numeric_limits<int>::max();
        
        // init
        profit[0] = 0;
        minPrice = prices[0];

        for(int i = 1; i < n; ++i){
            profit[i] = max(profit[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        
        return profit[n - 1];
    }
};