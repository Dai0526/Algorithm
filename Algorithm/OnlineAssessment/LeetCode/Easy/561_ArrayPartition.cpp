/*
https://leetcode.com/problems/array-partition/

Idea:
sort, then add every other numbers

*/


#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());
        int maxSum = 0;
        
        for(int i = 0; i < nums.size(); i+=2){
            maxSum += nums[i];
        }
        
        return maxSum;
    }
};