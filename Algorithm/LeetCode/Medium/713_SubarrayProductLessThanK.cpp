/*
https://leetcode.com/problems/subarray-product-less-than-k/submissions/
    subset is continous, thus there is a property for 2 ptrs:
    
    new subset number = right - left + 1
    e.g. 10, 5, 2, 6
    idx   0  1  2  3
    10 -> 0-0+1 = 1
    10, 5 -> 1-0+1 = 2  --> [5] and [10,5]
    10, 5, 2->2-0+1 = 3 --> [2] [5,2] [10,5,2]
    ...

*/
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1){
            return 0;
        }
        
        int n = nums.size();
        int ans = 0;
        int product = 1;
        int l = 0;
        
        for(int r = 0; r < n; ++r){
            
            product *= nums[r];
            
            while(product >= k){
                product /= nums[l];
                ++l;
            }
            
            ans += r - l + 1;
        }
     
        return ans;
    }
};