/*
https://leetcode.com/problems/longest-increasing-subsequence/submissions/
 DP 最长、优化问题
 
 Keey find lis taht each point before idx = i, and update lut[i]
 由后往前找，避免重复 ++i, --j, j永远是i的前面的元素
 transfer func: 
    if(nums[i] > nums[j]){
        lut[i] = max(lut[i], lut[j] + 1);
    }
    
     10  9  2  5  3  7  101  18
lut  1   1  1  2  2  3  4    4

最后找到lut中最大的值，也可以用一个参数去记录最大值

*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0){
            return 0;
        }
        
        // init look up table
        vector<int> lut(n, 1);
        int lis = 1;
        
        for(int i = 1; i < n; ++i){
            for(int j = i - 1; j >=0; --j){
                if(nums[j] < nums[i]){
                    lut[i] = max(lut[i], lut[j] + 1);
                }
            }
            lis = max(lis, lut[i]);
        }
        
        return lis;
    }
};