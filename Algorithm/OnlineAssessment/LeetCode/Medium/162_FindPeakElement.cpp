/*
https://leetcode.com/problems/find-peak-element/
1. Linear Scan -> once find a drop at i, return  i - 1

2. Binary Search
    find mid, check mid > mid + 1

*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 0){
            return -1;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1 < right){
            int mid = (right - left) / 2 + left;
            
            if(nums[mid] > nums[mid + 1]){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        
        if(nums[left] > nums[right]){
            return left;
        }
        
        return right;
    }
};