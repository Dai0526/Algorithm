/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

QFA: 
1. duplicated? yes
2. Ascending order? yes

Thus need to take care about duplicated item

add a check that 
            if(nums[mid] == nums[right]){
                --right;
                continue;
            }


*/
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(nums.size() < 1){
            return false;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left + 1 < right){
            
            int mid = left + (right - left) / 2;
            if(nums[mid] == nums[right]){
                --right;
                continue;
            }
            
            if(nums[mid] < nums[right]){
                if(nums[mid] < target && target <= nums[right]){
                    left = mid;
                }else{
                    right = mid;
                }
            }else{
                if(nums[mid] > target && target >= nums[left]){
                    right = mid;
                }else{
                    left = mid;
                }
            }
            
        }
        
        if(nums[left] == target){
            return true;
        }
        
        if(nums[right] == target){
            return true;
        }
        
        
        return false;
    }
};