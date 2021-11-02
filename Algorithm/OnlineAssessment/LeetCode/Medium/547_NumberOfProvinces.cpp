/*
DFS

*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        int count = 0;
        
        for(int i = 0; i < isConnected.size(); ++i){
            if(visited.find(i) == visited.end()){
                dfs(visited, isConnected, i);
                ++count;
            }
        }
        
        return count;
    }
    
    void dfs(unordered_set<int>& visited, vector<vector<int>>& isConnected, int curr){
        for(int i = 0; i < isConnected.size(); ++i){
            if(isConnected[curr][i] == 1 && visited.find(i) == visited.end()){
                visited.insert(i);
                dfs(visited, isConnected, i);
            }
        }
    }
};