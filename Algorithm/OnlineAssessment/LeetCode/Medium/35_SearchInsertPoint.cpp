/*
https://leetcode.com/problems/search-insert-position/
Search problem,

1. brute force -> O(n)
2. Binary search with upper bound

special case

nums[0]>target and nums[size -1] < target

Then do binary search, with right bound

remain left and right
if leftr == target, return left
else return right

如果不用 left+1< right模板
int searchInsert(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return left;
  }



*/
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(nums.size() == 0){
            return 0;
        }
        
        // extrem case
        if(nums[0] > target){
            return 0;
        }
        
        if(nums[size -1] < target){
            return size;
        }
        
        
        int left = 0; 
        int right = size - 1;
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                left = mid;
            }
            
        }
        
        if(nums[left] == target){
            return left;
        }
        
        return right;
    }
};