/*
DFS with backtracking
https://leetcode.com/problems/all-paths-from-source-to-target/
*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<vector<int>> ans;
        vector<int> path;
        
        path.push_back(0);
        dfs(graph, n - 1, 0, path, ans);
        
        return ans;
        
    }
    
    void dfs(vector<vector<int>>& graph, const int dest, int curr, vector<int>& path, vector<vector<int>>& ans){
        if(curr == dest){
            ans.push_back(path);
            return;
        }
        
        vector<int> nexts = graph[curr];
        
        for(int n : nexts){
            path.push_back(n);
            dfs(graph, dest, n, path, ans);
            path.pop_back();
        }
    }
};