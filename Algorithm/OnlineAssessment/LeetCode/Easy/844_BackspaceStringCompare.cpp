/*
https://leetcode.com/problems/backspace-string-compare/submissions/

Use stack

*/

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        vector<char> svec;
        vector<char> tvec;
        
        
        rmBackSpace(S, svec);
        rmBackSpace(T, tvec);
        
        if(svec.size() != tvec.size()){
            return false;
        }
        
        for(int i = 0; i < svec.size(); ++i){
            if(svec[i] != tvec[i]){
                return false;
            }
        }
        
        return true;
    }
    
    
    void rmBackSpace(const string& s, vector<char>& vec){
        
        stack<char> stk;
        
        for(char c : s){
            if(c == '#'){
                if(!stk.empty()) stk.pop();
            }else{
                stk.push(c);
            }
        }
        
        // add to vec
        while(!stk.empty()){
            vec.push_back(stk.top());
            stk.pop();
        }  
    }
    
};