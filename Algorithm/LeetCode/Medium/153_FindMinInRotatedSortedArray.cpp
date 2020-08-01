/*
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Binary Search
    - Always compare to the right end.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l = 0;
        int r = nums.size() -1;
        
        while(l + 1 < r){            
            int m = l + (r - l) / 2;
            
            if(nums[m] < nums[r]){
                r = m;
            }else{
                l = m;
            }
            
            //cout << "left = " << l << ", right = " << r << ", mid = " << m <<endl;
        }

        if(nums[l] < nums[r]){
            return nums[l];
        }

        return nums[r];
    }
};