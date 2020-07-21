/*
https://leetcode.com/problems/find-pivot-index/

right = sum
left = 0
move pivot index and get new left and right

*/

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n == 0){
            return -1;
        }
        
        if(n == 1){
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        for(int n : nums){
            right += n;
        }
        
        for(int i = 0; i < n; ++i){
            if(left == right - nums[i]){
                return i;
            } 
            
            right -= nums[i];
            left += nums[i];
        }
        
        return -1;
    }
};