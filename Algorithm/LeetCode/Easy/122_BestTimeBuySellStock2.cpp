/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Derive from init method, we know that sum all increasting will be the max profit, 
thus we can simplify the process by adding all increments.

*/


#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit_init(vector<int>& prices) {
        int days = prices.size();
        
        if(days == 0){
            return 0;
        }
        
        // init from day1
        int peak = prices[0];
        int down = prices[0];
        int max = 0;
        int i = 0;
        
        while(i < days - 1){
            //find the turnning point for down
            while(i < days -1 && prices[i] >= prices[i+1]){
                ++i;
            }
            
            down = prices[i];
            
            // find turning point for peak
            while(i < days - 1 && prices[i] <= prices[i+1]){
                ++i;
            }
            
            peak = prices[i];
            max += peak - down;
            
        }
        
        return max;
    }
    
    // tricky way - from above algorithm, we know that sum all increasting will be the max profit, 
    // thus we can simplify the process
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] <= prices[i - 1]){
                continue;
            }
            
            max += prices[i] - prices[i - 1];
        }
        
        return max;
        
    }
    
    
    
};