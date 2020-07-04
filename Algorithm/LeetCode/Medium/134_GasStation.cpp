/*
https://leetcode.com/problems/gas-station/

1. If a car can finish route, total remain gas must >=0
   Thus we need a variable to count all gas.

2. Then the only problem left is to find the start idx.
    Keep reset start idx if current tank is < 0

*/
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        int current = 0;
        int total = 0;
        int start = 0;
        for(int i = 0; i < n; ++i){
            
            total += gas[i] - cost[i];
            current += gas[i] - cost[i];
            
            if(current < 0){
                // reset
                start = i + 1;
                current = 0;
                continue;
            } 
        }
        
        return total >= 0 ? start : -1;
    }
};