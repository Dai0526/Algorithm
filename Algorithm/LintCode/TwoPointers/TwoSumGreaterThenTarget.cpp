/*
443. Two Sum - Greater than target
https://www.lintcode.com/problem/two-sum-greater-than-target/
Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.

Example 1:
Input: [2, 7, 11, 15], target = 24, Output: 1
Explanation: 11 + 15 is the only pair.

Example 2:
Input: [1, 1, 1, 1], target = 1, Output: 6

Challenge
Do it in O(1) extra space and O(nlogn) time.

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        int nSize = nums.size();
        
        if(nSize < 2){
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nSize - 1;
        
        int count = 0;
        
        while(left < right){
            if(nums[left] + nums[right] <= target){
                ++left;
            }else{

                count += right - left;
                --right;
            }
        }
        
        return count;
    }
};