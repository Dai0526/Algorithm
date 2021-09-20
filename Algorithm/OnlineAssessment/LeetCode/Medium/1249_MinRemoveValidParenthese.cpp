/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Use a stack, 
if '('
 push to stack
if ')'
    if stack empty
        add idx
    else
        pop

check if there is any remainning (, if existd, add its index to list


*/
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len = s.length();
        
        vector<bool> check(len, true);
        stack<int> leftIdx;
        
        for(int i = 0; i < len; ++i){
            char ch = s[i];
            
            if(ch == '('){
                leftIdx.push(i);
            }else if(ch == ')'){
                if(leftIdx.empty()){
                    check[i] = false;
                }else{
                    leftIdx.pop();   
                }
            }
        }
        
        // check remaining left breace
        while(!leftIdx.empty()){
            check[leftIdx.top()] = false;
            leftIdx.pop();
        }
        
        stringstream ss;
        for(int i = 0; i < len; ++i){
            if(check[i] == false){
                continue;
            }
            
            ss << s[i];
        }
        
        return ss.str();
    }
};