/*
https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int i = nums.size() - 1; i > 0 ; --i){
            count += nums[i] - nums[0];
        }
        
        return count;
    }
};