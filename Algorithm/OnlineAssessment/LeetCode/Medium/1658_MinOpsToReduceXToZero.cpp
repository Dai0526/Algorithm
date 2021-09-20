/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

1. If it exists an answer, then it means we have a subarray in the middle of original array whose sum is == totalSum - x
2. If we want to minimize our operations, then we should maximize the length of the middle subarray.

--> Find the Longest Subarray with Sum Equals to TotalSum - X
We could simply use Map + Prefix Sum to get it!

*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //get target sum
        int target = -x;
        for(int n : nums){
            target += n;
        }
        
        if(target == 0){
            return nums.size(); // all elements
        }
        
        if(target < 0){
            return -1; // since all are positive
        }
        
        int maxLen = numeric_limits<int>::min();
        int sum = 0;
        int left = 0;
        
        // sliding window
        for(int i = 0; i < nums.size(); ++i){
            if(sum < target){
                sum += nums[i];
            }
            
            while (sum >= target) {
				if (sum == target) {
					maxLen = max(maxLen, i - left + 1);
				}
                
                // moving left boundary
				sum -= nums[left];
                ++left;
			}
            
        }
        
        
        if(maxLen == numeric_limits<int>::min()){
            return -1;
        }
   
        return nums.size() - maxLen;
        
    }
};