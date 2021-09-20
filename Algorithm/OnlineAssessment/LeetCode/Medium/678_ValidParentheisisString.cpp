/*
by observation, number of ( and ) after elimination, if less then * then return true

*/

#include <stack>
using namespace std;
class Solution {
public:
 
    bool checkValidString(string s) {
        
        stack<char> star;
        stack<char> stk;
        
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            
            
            if(c == '*'){
                star.push(i);
                continue;
            }
            
            if(c == '('){
                stk.push(i);
            }else if(c == ')'){
                if(!stk.empty()){
                    stk.pop();
                }else if(star.empty()){
                    return false;
                }else{
                    star.pop();
                }
            }
        }
        
        // after above processing, it could be ( and * left, ) case is handled, keep eliminating rest
        // What'smore, * must appear at the right side of '('

        while(!stk.empty() && !star.empty()){
            // compare idx
            if(stk.top() > star.top()){
                return false;
            }
            
            stk.pop();
            star.pop();
        }
        
        return stk.empty();
    }
    
};