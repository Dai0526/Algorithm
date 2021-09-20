#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        if(strs.size() == 0){
            return ans;
        }
        
        unordered_map<string, vector<string>> ana;
        
        for(const string &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            if(ana.find(temp) != ana.end()){
                ana[temp].push_back(s);
            }else{
                vector<string> strVec;
                strVec.push_back(s);
                ana[temp] = strVec;
            }
            
        }
        
                
        for(auto& item : ana){
            ans.push_back(item.second);
        }
        
        return ans;
        
    }
};