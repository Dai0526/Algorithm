#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        if(n > 45){
            return vector<vector<int>>();    
        }
        
        vector<bool> visited(9, false);
        vector<int> comb;
        vector<vector<int>> res;
            
        dfs(n, k, 0, res, comb);
        return res;
    }

private:
    void dfs(int remain, const int k, int idx, vector<vector<int>>& res, vector<int>& comb){
        if(remain == 0 && comb.size() == k){
            res.push_back(comb);
            return;
        }
        
        if(remain < 0 || comb.size() == k){
            return; // invalid
        }
        
        for(int i = idx; i < 9; ++i){
            comb.push_back(i + 1);
            dfs(remain - i - 1, k, i + 1, res, comb);
            comb.pop_back();
        }
        
    }
};