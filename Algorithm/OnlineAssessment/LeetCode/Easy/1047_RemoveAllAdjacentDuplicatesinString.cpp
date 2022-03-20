/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        stk.push(s[0]);
        
        for(int i = 1; i < s.size(); ++i){
            if(!stk.empty() && stk.top() == s[i]){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
        
        stringstream ss;
        while(!stk.empty()){
            ss << stk.top();
            stk.pop();
        }
        
        string ans = ss.str();
        reverse(ans. begin(), ans.end());
        
        return ans;
        
    }
};