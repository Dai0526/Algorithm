/*
https://leetcode.com/problems/valid-parentheses/
Start from left to right,
push any left bracer/bracket into stack

if there is a right, check stack top

*/

#include <stack>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> left;
        left['('] = 0;
        left['['] = 1;
        left['{'] = 2;
        
        unordered_map<char, int> right;
        right[')'] = 0;
        right[']'] = 1;
        right['}'] = 2;
        
        
        stack<char> stk;
        for(int i = 0; i < s.length(); ++i){
            if(left.find(s[i]) != left.end()){
                stk.push(s[i]);
            }
            
            if(right.find(s[i]) != right.end()){
                if(stk.empty()){
                    return false;
                }
                
                if(right[s[i]] != left[stk.top()]){
                    return false;
                }else{
                    stk.pop();
                }
            }
            
        }
        
        return stk.empty() == true ? true : false;
    }

public:
    
    enum ParentheseType{
        NONE = 0,
        LEFT = 1,
        RIGHT = 2
    };
    
    bool isValid2(string s) {
        
        unordered_map<char, char> parenthesesPair;
        parenthesesPair[')'] = '(';
        parenthesesPair[']'] = '[';
        parenthesesPair['}'] = '{';
        
        stack<char> stk;
        
        for(char c : s){
            ParentheseType t = GetPrentheseType(c);
            switch(t){
                case ParentheseType::LEFT:
                    stk.push(c);
                    break;
                case ParentheseType::RIGHT:
                    if(stk.empty()){
                        return false;
                    }
                
                    if(parenthesesPair[c] != stk.top()){
                        return false;
                    }
                    stk.pop();
                    break;
                default:
                    break; 
            }
            
        }
        
        return stk.empty();
    }
    
    ParentheseType GetPrentheseType(char c){
        if(c == '[' || c == '(' || c == '{'){
            return ParentheseType::LEFT;
        }else if(c == ']' || c == ')' || c == '}'){
            return ParentheseType::RIGHT;
        }
         
        return ParentheseType::NONE;
    } 
    
};


