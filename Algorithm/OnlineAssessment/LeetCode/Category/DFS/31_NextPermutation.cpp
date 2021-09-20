/*
https://leetcode.com/problems/next-permutation/

nums 5 2 4 3 1
idx  0 1 2 3 4

从后开始，找到第一个降序 i = 1
再从后往前，找到第一个比 nums[i]要大的数， j = 3, 

互换 i 和 j, 得到
swap(nums[i], nums[j])
nums 5 3 4 2 1
idx  0 1 2 3 4

新的排序的 i = 1 的位置就是新的排列的开始，i之后的数组一定是降序
因为得到了新的排列，那一定是从最小开始，所以要让后面的数组升序，只要reverse一下就好

reverse(BeginItr+i+1, endItr)
nums 5 3 1 2 4
idx  0 1 2 3 4

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int i = size - 2;
        // find the index of first increasing
        for(i; i > i ; --i){
            if(nums[i] < nums[i + 1]){
                break;
            }
        }
        
        if(i < 0){
            // whole nums in descend order
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // from [i+ 1, size - 1], find idx that nums[idx] > nums[i]
        int j = size - 1;
        for(j; j >= 0; --j){
            if(nums[j] > nums[i]){
                break;
            }
        }
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        
        reverse(nums.begin() + i + 1, nums.end());
    }
};