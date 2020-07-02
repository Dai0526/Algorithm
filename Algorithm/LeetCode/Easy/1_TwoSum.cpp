/*
https://leetcode.com/problems/two-sum/
*/

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> rec; // value , idx
        vector<int> ans(2, 0);
        
        for(int i = 0; i < nums.size(); ++i){
            
            int n = nums[i];
            int remain = target - n;
            
            if(rec.find(remain) != rec.end()){
                ans[0] = rec[remain];
                ans[1] = i;       
                break;
            }
            
            rec[n] = i;
        }
        
        return ans;
    }
};