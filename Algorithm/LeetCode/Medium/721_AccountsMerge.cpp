// build a graph and do dfs
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // build a graph
        unordered_map<string, unordered_set<string>> graph; // graph between emails
        unordered_map<string, string> email2Name;
        
        for(int i = 0; i < accounts.size(); ++i){
            string user = accounts[i][0];
            
            for(int j = 1; j < accounts[i].size(); ++j){
                string email = accounts[i][j];
                
                graph[email].insert(accounts[i][1]);
                graph[accounts[i][1]].insert(email);
                email2Name[email] = user;
            }
        }
          
        unordered_set<string> recorded; 
        vector<vector<string>> merged;
        
        for(auto &p : graph){
            string email = p.first;
            
            if(recorded.find(email) != recorded.end()){
                continue;
            }
            
            recorded.insert(email);
            
            vector<string> user;
            user.push_back(email2Name[email]); // add name to first
            
            stack<string> stk;
            stk.push(email);
            
            while(!stk.empty()){
                string temp = stk.top();
                stk.pop();
                
                user.push_back(temp);
                
                for(const string &e : graph[temp]){
                    if(recorded.find(e) == recorded.end()){
                        stk.push(e);
                        recorded.insert(e);
                    }
                }   
            }
            
            sort(user.begin() + 1, user.end());
            merged.push_back(user);
        }
            
        return merged;        
    }
};