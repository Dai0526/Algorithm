/*
585. Maximum number in Mountain Sequence
https://www.lintcode.com/problem/maximum-number-in-mountain-sequence/
Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.

Example 1:
Input: nums = [1, 2, 4, 8, 6, 3] 
Output: 8
Example 2:

Input: nums = [10, 9, 8, 7], 
Output: 10
Notice
Arrays are strictly incremented, strictly decreasing
*/
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        int n = nums.size();
        
        if(n == 0){
            return -1;
        }
        
        int begin = 0;
        int end = n - 1;
        
        while(begin + 1 < end){
            
            int mid = begin + (end - begin) / 2;
            
            if(nums[mid] > nums[mid + 1]){
                //decrease, thus
                end = mid;
            }else{
                begin = mid;
            }
        }
        
        if(nums[begin] > nums[end]){
            return nums[begin];
        }
        
        return nums[end];
    }
};