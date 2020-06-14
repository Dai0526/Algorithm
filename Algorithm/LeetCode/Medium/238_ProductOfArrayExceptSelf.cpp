/*
https://leetcode.com/problems/product-of-array-except-self/
QFA: time complexity? Space complexity?
Brute force n^2
O(n) ?

IDEA->
Init Product = 1 before do left and do right
array                              x, y, z
left  = product * nums[i - 1]      1, x, xy
right = product * nums[j]          yz,z, 1
out = left * right                 yz, xz, xy

可以在同一个array上进行操作，减少space

*/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> ans(size, 1);
        
        // get product from left to right
        for(int i = 1; i < size; ++i){
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        
        // get product from right to left
        int product = 1;       
        for(int j = size - 1; j >= 0; --j){
            ans[j] = product * ans[j];
            product *= nums[j];
        }
        
        return ans;
    }
};