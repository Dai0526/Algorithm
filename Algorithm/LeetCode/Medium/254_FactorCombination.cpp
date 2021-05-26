class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        if(n == 1){
            return ans;
        }
        
        vector<int> comb;
        dfs(ans, comb, n, 2);
        
        ans.pop_back();
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& comb, int n, int factor){
        for(int i = factor; i <= n/i; ++i){
            if(n % i != 0){
                continue;
            }
            
            comb.push_back(i);
            dfs(ans, comb, n/i, i);
            comb.pop_back();
        }
        
        comb.push_back(n);
        ans.push_back(comb);
        comb.pop_back();    
    }
};

class Solution2 {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        if(n == 1){
            return ans;
        }
        
        vector<int> comb;
        dfs(ans, comb, n, 2);
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& ans, vector<int>& comb, int n, int factor){
        int upperbound = sqrt(n);
        for(int i = factor; i <= upperbound; ++i){
            if(n % i != 0){
                continue;
            } 
            
            vector<int> prev(comb.begin(), comb.end());
            prev.push_back(i);
            dfs(ans, prev, n / i, i);
            prev.push_back(n / i);
            ans.push_back(prev);
        }
    }
};