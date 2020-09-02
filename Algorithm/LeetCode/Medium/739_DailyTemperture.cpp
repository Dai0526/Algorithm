/*
https://leetcode.com/problems/daily-temperatures/

*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        int n = T.size();   
        vector<int> ans(n, 0);
        stack<int> stk;  // idx
        
        for(int i = n - 1; i >= 0; --i){
            int curr = T[i];
            while(!stk.empty() && T[stk.top()] <= curr){
                stk.pop();
            }
            
            if(stk.empty()){
                ans[i] = 0;
            }else{
                ans[i] = stk.top() - i;
            }
            
            stk.push(i);
        }
        
        return ans;
    }
    
    vector<int> dailyTemperatures_slow(vector<int>& T) {
        
        int n = T.size();   
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; ++i){
            int today = T[i];
            for(int j = i + 1; j < n; ++j){
                if(T[j] > T[i]){
                    ans[i] = j - i;
                    break;
                }
            }
        }
        
        return ans;
    }
};