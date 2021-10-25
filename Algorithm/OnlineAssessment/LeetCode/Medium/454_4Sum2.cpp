/*
https://leetcode.com/problems/4sum-ii/
divide and conquer to reduce n^4 to n^2

*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> info;
        for(int c : nums3){
            for(int d : nums4){
                ++info[c + d];
            }
        }
        
        int count = 0;
        for(int a : nums1){
            for(int b : nums2){
                int tar =  0 - a - b;
                if(info.find(tar) != info.end()){
                    count += info[tar];
                }
            }
        }
        
        return count;
    }
};