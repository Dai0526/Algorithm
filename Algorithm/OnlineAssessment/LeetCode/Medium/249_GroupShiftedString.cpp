/* 
find base string as a key for each candidate, the add to map

*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
                
        unordered_map<string, vector<string>> temp;
        
        for(const string& s : strings){
            int nDiff = s[0] - 'a';
            stringstream ss;
            for(char c : s){
                ss << (c - nDiff) % ('z' - 'a' + 1); // circular z -> back to a
            }
            
            string baseStr = ss.str();
            
            temp[baseStr].push_back(s);
        }
        
        vector<vector<string>> ans;
        for(const pair<string, vector<string>>& pr : temp){
            vector<string> group;
            for(const string& g : pr.second){
                group.push_back(g);
            }
            ans.push_back(group);
        }
        
        return ans;
    }
};