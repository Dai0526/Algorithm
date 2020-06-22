/*
https://leetcode.com/problems/combination-sum-ii/

DFS recursion with 
    Remove duplicate for the first element in a combi
        1. Sort first 
        2. check nums[i] != nums[i-1]

It be only used once -> dfs(nums, i + 1, remain - nums[i], rec, out); i+1 for the next starting choice
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        
        if(size == 0){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> out;
        vector<int> current;
        
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, 0, target, current, out);
        
        return out;
    }
    
    
    void dfs(const vector<int>& nums, int idx, int remain, vector<int>& rec, vector<vector<int>>& out){
        if(remain < 0){
            return;
        }
        
        if(remain == 0){
            out.push_back(rec);  // find a combi
            return;
        }
        
        
        for(int i = idx; i < nums.size(); ++i){
            if(i > idx && nums[i] == nums[i - 1]){
                continue;
            }
            rec.push_back(nums[i]);            
            dfs(nums, i + 1, remain - nums[i], rec, out);
            rec.pop_back();
        }
    }
};