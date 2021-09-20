/*
494 Target Sum - DFS
https://leetcode.com/problems/target-sum/
*/
#include <vector>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        long long count = 0;
        assign(nums, 0, S, count);
        
        return count;
    }
    
    void assign(vector<int>& nums, int idx, long long remain, long long& count){
        if(idx == nums.size()){
             if(remain == 0){
                 ++count;
             }  
            return;
        }
        
        assign(nums, idx + 1, remain - nums[idx], count);
        assign(nums, idx + 1, remain + nums[idx], count);       
    }
    
};