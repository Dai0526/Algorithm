/*
https://leetcode.com/problems/maximum-average-subarray-i/
Sliding window

*/

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // n >= k
        double sum = 0.0;
        for(int i = 0; i < k; ++i){
            sum += nums[i];
        }
       
        if(nums.size() == k){
            return sum / k;
        }
        
        double maxSum = sum;
        for(int i = k; i < nums.size(); ++i){
            sum += nums[i] - nums[i - k];
            maxSum = maxSum >= sum ? maxSum : sum;
        }
        
        return maxSum / k;
    }
};