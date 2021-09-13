/*
has same elements, then it is able to be converted

*/

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        if(target.size() != arr.size()){
            return false;
        }
        
        unordered_map<int, int> freq;
        
        for(int i = 0; i < target.size(); ++i){
            ++freq[target[i]];
            --freq[arr[i]];
        }
        
        for(const pair<int, int> &pr : freq){
            if(pr.second != 0){
                return false;
            }
        }
        
        return true;
        
    }
};