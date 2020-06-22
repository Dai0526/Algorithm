/*
DFS - same idea as subset or combination
This problem is to insert 3 dots to the given string.



*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.length() == 0){
            return vector<string>();
        }
        
        vector<vector<string>> res;
        vector<string> temp;
        
        dfs(s, 0, temp, res);
        
        vector<string> ans;
        for(const vector<string>& vec : res){
            stringstream ss;
            ss << vec[0];
            for(int i = 1; i < vec.size(); ++i){
                ss << "." << vec[i];
            }
            ans.push_back(ss.str());
        }
        
        return ans;
    }
    
    void dfs(const string &s, int idx, vector<string>& temp, vector<vector<string>>& res){
        if(temp.size() > 4){
            return;
        }
        
        if(temp.size() == 4 && idx == s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.length(); ++i){
            // total 4 segments
            if(i >= idx + 3){
                break;
            }
            
            // take the rest and check if it works
            string str = s.substr(idx, i - idx + 1);
            if((str[0] == '0' && str.length() > 1) || stoi(str) > 255){
                continue;
            }
            
            temp.push_back(str);
            dfs(s, i + 1, temp, res);
            temp.pop_back();   
        }
        
    }
};