/*
No duplicated

简单binary search搞定
*/


#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        if(n < 1){
            return -1;
        }
        
        int left = 0;
        int right = n - 1;
        
        
        while(left + 1 < right){
            
            int mid = left + (right - left)/2;
            
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
        
        if(nums[right] == target){
            return right;
        }
        
        if(nums[left] == target){
            return left;
        }
        
        return -1;
        
    }
};