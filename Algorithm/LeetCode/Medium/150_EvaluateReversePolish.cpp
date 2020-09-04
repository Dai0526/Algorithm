/*
https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(const string& tk : tokens){
            
            if(tk.size() != 1 || isdigit(tk[0])){
                stk.push(stoi(tk));
                continue;
            }
            
            // expression is always valid so we can pop 2 items out
            int snd = stk.top();
            stk.pop();
            int fst = stk.top();
            stk.pop();
            
            if(tk.compare("+") == 0){
                stk.push(fst + snd);
            }else if(tk.compare("-") == 0){
                stk.push(fst - snd);
            }else if(tk.compare("*") == 0){
                stk.push(fst * snd);
            }else if(tk.compare("/") == 0){
                stk.push(fst / snd);
            }
        }
        
        return stk.top();
    }
};