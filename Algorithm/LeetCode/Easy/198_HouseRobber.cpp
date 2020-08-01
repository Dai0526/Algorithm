/*
Dynamic Programming
https://leetcode.com/problems/house-robber/solution/

lut[n]

initalize - first two days are independent
    lut[0] = nums[0]
    lut[1] = nums[1]

Transfer Function
We know that day 3's max profit depends on max of previous two days.
Transfer function is -> lut[n] = max[lut[n-2] + nums[n], lut[n-1]];

To Simpilify it, 
lut[0] = 0 -> house 0
lut[1] = nums[0] -> house 1
thus 
        for(int i = 2; i < n + 2; ++i){
            lut[i] = max(lut[i - 1] + nums[i - 1], lut[i - 1]);
        }


*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        vector<int> lut(n + 1, 0);
        lut[1] = nums[0];
        
        for(int i = 2; i < n + 2; ++i){
            lut[i] = max(lut[i - 1] + nums[i - 1], lut[i - 1]);
        }
        
        return lut[n]; // return last
    }
};