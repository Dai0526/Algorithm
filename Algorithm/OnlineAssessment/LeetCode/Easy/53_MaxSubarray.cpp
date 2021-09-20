/*
最大子序列之和 = 当前子序列之和 - 之前最小前缀和

Preix sum

idx         0  1  2  3  4  5  6  7  8
           -2  1 -3  4 -1  2  1 -5  4
prefix     -2 -1 -4  0 -1  1  2 -3  1
minPrefix  -2 -2 -4 -4 -4 -4 -4 -4 -4
maxSum     -2  1  1  4  4  5  6  1  5

e.g.

idx = 1
prefixSum = -2 + 1 = -1
maxSum = max(-2, (-1) - (-2)) = 1
minPrefixSum = min(-2, -1) = -2

idx = 2
prefixSum = -1 - 3 = -4
maxSum = max(1, (-4) - (-2)) = 1
minPrefixSum = min(-2, -1) = -4
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0){
            return 0;
        }
        
        int prefixSum = 0;
        int minPrefixSum = 0;
        int maxSubarry = numeric_limits<int>::min();
        
        for(int i = 0; i < size; ++i){
            prefixSum += nums[i];
            maxSubarry = max(maxSubarry, prefixSum - minPrefixSum);
            minPrefixSum = min(minPrefixSum, prefixSum);
        }

        return maxSubarry;
    }
};