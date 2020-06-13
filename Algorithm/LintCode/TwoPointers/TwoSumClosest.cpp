/*
533. Two Sum - Closest to target
https://www.lintcode.com/problem/two-sum-closest-to-target/
Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.
Return the absolute value of difference between the sum of the two integers and the target.

Example1
Input:  nums = [-1, 2, 1, -4] and target = 4, Output: 1

Explanation:
The minimum difference is 1. (4 - (2 + 1) = 1).

Example2
Input:  nums = [-1, -1, -1, -4] and target = 4, Output: 6

Explanation:
The minimum difference is 6. (4 - (- 1 - 1) = 6).

Challenge
Do it in O(nlogn) time complexity.

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        int nSize = nums.size();
        
        if(nSize < 2){
            return 0;
        }
        
        int left = 0;
        int right = nSize - 1;
        int minDiff = std::numeric_limits<int>::max();
        
        std::sort(nums.begin(), nums.end());
        
        while(left < right){
            
            int sum = nums[left] + nums[right];
            
            if(sum < target){
                int res = target - sum;
                minDiff = res < minDiff ? res : minDiff;
                ++left;
            }else{
                int res = sum - target;
                minDiff = res < minDiff ? res : minDiff;
                --right;
            }
            
        }
        
        return minDiff;
    }
};