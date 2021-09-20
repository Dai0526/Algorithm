/*
https://leetcode.com/problems/combination-sum/

QFA?

Sorted? Negative Number? Zero?

IDEA:
Since input has no duplication, just add one, do dfs for next, remove it.

DFS with recursion
dfs( target, idx, candidates, out)

Node that one can repeat many time,for example
[2,3,5] 8
can have 2,2,2,2
        for i to size - 1
thus -> dfs(nums, i, remain - nums[i], rec, out);  // i for repating itself for next start

*/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size = candidates.size();
        
        if(size == 0){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> out;
        vector<int> current;
        
        dfs(candidates, 0, target, current, out);
        
        return out;
    }
    
    
    void dfs(const vector<int>& nums, int idx, int remain, vector<int>& rec, vector<vector<int>>& out){
        if(remain < 0){
            return;
        }
        
        if(remain == 0){
            // find a combi
            out.push_back(rec);
            return;
        }
        
        for(int i = idx; i < nums.size(); ++i){
            rec.push_back(nums[i]);
            
            dfs(nums, i, remain - nums[i], rec, out);
            
            rec.pop_back();
        }
    }
    
};