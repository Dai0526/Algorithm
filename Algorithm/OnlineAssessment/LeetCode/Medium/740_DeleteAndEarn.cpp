/*
https://leetcode.com/problems/delete-and-earn/
2 2 3 3 3 4
Similiar to House Robbing problem, you cant use adjacent numbers. Thus,

1. create a array vector<int> pts from 0 to largest number in given array
2. pts[n] = n * count of n
3. do house rob and you can get the max points you can get

*/

#include <algorithm>

using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        auto it = max_element(nums.begin(), nums.end());
        int maxNum = *it;
        vector<int> pts(maxNum + 1);
        
        for(int &n : nums){
            pts[n] += n;
        }
        
        vector<int> lut(pts.size(), 0);
        
        lut[1] = pts[1];

        for(int i = 2; i < lut.size(); ++i){
            lut[i] = max(lut[i - 2] + pts[i], lut[i - 1]);
        }
        
        return lut[pts.size() - 1];
    }
};