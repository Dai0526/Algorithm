/*
https://leetcode.com/problems/subsets/

dfs - recursion with backtracking

        vector<vector<int>> out -> output
        vector<int> subset -> each subset
        
        dfs(nums, 0, subset, out);

1. every recursion is a subset, thus, add subset to out
2. for each idx from size - 1
add to subset
dfs
pop


*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> out;
        vector<int> subset;
        
        dfs(nums, 0, subset, out);
        
        return out;
    }
    
    
    void dfs(const vector<int>& nums, int idx, vector<int>& subset, vector<vector<int>>& out){
        
        out.push_back(subset);
        
        
        for(int i = idx; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            dfs(nums, i + 1, subset, out);
            subset.pop_back();
        }
        
    }
};