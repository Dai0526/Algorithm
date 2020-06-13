/*
https://leetcode.com/problems/permutations-ii/

DFS with backtracking
Use a vector to track visited idx
    once perm.size == nums.size, add to result
            if(visited[i]){
                continue;
            }
            
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0){
            return vector<vector<int>>();
        }
        
        vector<bool> visited(size, false);
        vector<int> perm;
        vector<vector<int>> out;
        
        sort(nums.begin(), nums.end());
        
        dfs(nums, visited, perm, out);
        
        return out;
        
    }
    
    
    void dfs(const vector<int>& nums, vector<bool>& visited, vector<int>& candidate, vector<vector<int>>& out){
        if(nums.size() == candidate.size()){
            out.push_back(candidate);
            return;
        }
              
        for(int i = 0; i < nums.size(); ++i){
            
            if(visited[i]){
                continue;
            }
            
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
                 
            candidate.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, candidate, out);
            candidate.pop_back();
            visited[i] = false;
            
        }
        
    }
};