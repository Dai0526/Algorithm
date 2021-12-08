/*
https://leetcode.com/problems/range-addition/
cache all modifications, then do a partial sum

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        
        int nUpdates = updates.size();
        
        for(int i = 0; i < nUpdates; ++i){
            vector<int> temp = updates[i];
            
            int start = temp[0];
            int end = temp[1];
            int inc = temp[2];
            
            ans[start] += inc;
            
            if(end + 1 < length){
                ans[end + 1] -= inc;
            }
            
        }
        
        
        // calculate partial sum
        for(int i = 1; i < length; ++i){
            ans[i] += ans[i - 1];
        }
        
        return ans;
        
    }
};