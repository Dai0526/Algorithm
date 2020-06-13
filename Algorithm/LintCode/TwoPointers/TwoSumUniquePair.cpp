/*
587. Two Sum - Unique pairs
https://www.lintcode.com/problem/two-sum-unique-pairs/
Given an array of integers, find how many unique pairs in the array such that their sum is equal to a specific target number. Please return the number of pairs.

Example 1:
Input: nums = [1,1,2,45,46,46], target = 47 
Output: 2

Explanation:
1 + 46 = 47
2 + 45 = 47

Example 2:
Input: nums = [1,1], target = 2 
Output: 1
Explanation:
1 + 1 = 2

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        // two pointers, keey move until it is not the same  as prev target, then check sum
        
        int nSize = nums.size();
        if(nSize < 2){
            return 0;
        }
        
        int left = 0;
        int right = nSize - 1;       
        int count = 0;
        
        std::sort(nums.begin(), nums.end());
        
        while(left < right){

            if(nums[left] + nums[right] == target){
                ++count;
                --right;
                ++left;
                
                while(nums[left] == nums[left - 1] && left < right){
                    ++left;
                }
                
                while(nums[right] == nums[right + 1] && left < right){
                    --right;
                }
                
            }else if(nums[left] + nums[right] > target){
                --right;
            }else{
                ++left;
            }
        }
               
        return count;
    }
};