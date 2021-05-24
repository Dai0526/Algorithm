#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> visited;
        
        return dfs(s, 0, dict, visited);
    }
    
    vector<string> dfs(const string& s, int idx, unordered_set<string>& dict, unordered_map<int, vector<string>>& visited){
        
        if(visited.find(idx) != visited.end()){
            return visited[idx];
        }
        
        string str;
        
        for(int i = idx; i < s.length(); ++i){
            str += s[i];
            
            if(dict.find(str) == dict.end()){
                continue;
            }
            
            if(i == s.length() - 1){
                visited[idx].push_back(str);
            }else{
                vector<string> segs = dfs(s, i + 1, dict, visited);
                for(string& seg : segs){
                    visited[idx].push_back(str + " " + seg);
                }
            }
        }

        return visited[idx];        
    }
    
};