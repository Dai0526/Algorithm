/*
https://leetcode.com/problems/permutations/

Recursively find all permutations

DFS with a visited map or set for backtracking.

If you want in order, need to sort original vector first.


*/

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size == 0){
            return vector<vector<int>>();
        }
        
        set<int> visited; // record visited index
        vector<int> permutation;
        vector<vector<int>> out;
        dfs(nums, visited, permutation, out);
        
        return out;
        
    }
    
    void dfs(const vector<int>& nums, set<int>& visited, vector<int>& perm, vector<vector<int>>& out){
        if(nums.size() == perm.size()){
            out.push_back(perm);
            return;
        }
        
        for(int i = 0; i< nums.size(); ++i){
            if(visited.find(i) != visited.end()){
                continue;
            }
            
            if( i > 0 && nums[i] == nums[i-1] && visited.find(i-1) != visited.end()){
                continue;
            }
            
            visited.insert(i);
            perm.push_back(nums[i]);
            dfs(nums, visited, perm, out);
            perm.pop_back();
            visited.erase(i);
        }
        
    }
    
};