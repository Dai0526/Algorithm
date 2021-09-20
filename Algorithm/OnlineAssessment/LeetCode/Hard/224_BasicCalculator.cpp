/*

QFA: Constrain numrics, non-negative, plus and minus only, non-negative


IDEA
Use two stacks
a. numStack
b. opsStack

1. Parse string from right to left

if digit, keep parsing until there is a space, push it into stack_num
if +/-, pop 2 nums from stack_num, and do corresponding operation
if (, start to evalute until see a )
if ) push it to opStack

*/
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    
    int calculate(string s) {
        stack<int> digits;
        stack<int> ops;
        
        int ans = 0;
        int sign = 1;
        
        int i = 0;
        while(i < s.length()){
            int curr = 0;
            while(isdigit(s[i]) && i < s.size()){
                curr = curr * 10 + (s[i] - '0');
                ++i;
            }
            
            ans += curr * sign;
            
            if(i == s.size()){
                break;
            }
            
            if(s[i] == '+'){
                sign = 1;
            }else if(s[i] == '-'){
                sign = -1;
            }else if(s[i] == '('){
                digits.push(ans);
                ans = 0;
                
                ops.push(sign);
                sign = 1;
            }else if(s[i] == ')'){
                ans *= ops.top(); // apply sign
                ops.pop();
                ans += digits.top();
                
                digits.pop();
            }
            
            ++i;
        }
          
        return ans;
    }
};