/*
https://leetcode.com/problems/combinations/

1. DFS back tracking 

vector<vector<int>> out -> save all results
vector<int> comb -> save current result
0 is begin idx
k is size of comb

dfs(nums, 0, k, comb, out);

recursion:
when comb.size() == k, return

other wise, from idx to size - 1
add to comb
dfs
pop out from comb


*/


#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        if(k > n){
            return vector<vector<int>>();
        }
        
        vector<int> nums(n);
        
        for(int i = 0; i < n; ++i){
            nums[i] = i + 1;
        }
        
        vector<vector<int>> out;
        vector<int> comb;
        
        dfs(nums, 0, k, comb, out);
        
        return out;
    }
    
    void dfs(const vector<int>& nums, int idx, int k, vector<int>& comb, vector<vector<int>>& out){
        
        if(comb.size() == k){
            out.push_back(comb);
            return;
        }
        
        for(int i = idx; i < nums.size(); ++i){
            
            comb.push_back(nums[i]);
            dfs(nums, i + 1, k, comb, out);
            comb.pop_back();
        }
        
        
    }
    
};