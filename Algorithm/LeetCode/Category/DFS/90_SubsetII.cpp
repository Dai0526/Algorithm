
/*
https://leetcode.com/problems/subsets-ii/

contain duplicated [1,2,2]
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

Sort array First in convenient of skipping duplicated

DFS to find all possible solution
注意跳过的条件
    if(i > 0 && nums[i] == nums[i-1] && i > idx){
        continue;
    }
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0){
            return vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> subset;
        
        dfs(nums, 0, subset, res);
        
        return res;
    }
    
    
    void dfs(vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& res){
        res.push_back(subset);
        
        for(int i = idx; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1] && i > idx){
                continue;
            }
            
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, res);
            subset.pop_back();
        }
        
    }
};