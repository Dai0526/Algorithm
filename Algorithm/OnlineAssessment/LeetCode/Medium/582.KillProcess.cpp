/*
https://leetcode.com/problems/kill-process/
build a graph, then kill

*/

#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> procMap; // ppid, pid
        
        // build graph
        int n = pid.size();
        for(int i = 0; i < n; ++i){
            int parent = ppid[i];
            int child = pid[i];
            procMap[parent].push_back(child);
        }
        
        
        vector<int> ans;
        ans.push_back(kill);
        GetAllChildProc(procMap, ans, kill);
        
        return ans;  
    }
    
    
    void GetAllChildProc(unordered_map<int, vector<int>>& procs, vector<int>& killed, int target){
        if(procs.find(target) == procs.end()){
            return;
        }
        
        for(int pid : procs[target]){
            killed.push_back(pid);
            GetAllChildProc(procs, killed, pid);
        }
    }
    
};