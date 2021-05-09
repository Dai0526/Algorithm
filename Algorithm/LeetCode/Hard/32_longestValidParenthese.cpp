
/*

Use stack

*/

#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0;
        stack<int> stk;
        stk.push(-1);
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i); // push to stack as a index mark to update where the new beginning is
                }else{
                    length = max(length, i - stk.top());
                }
            }
        }
        
        return length;
                   
    }
};