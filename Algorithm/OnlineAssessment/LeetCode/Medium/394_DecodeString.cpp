/*
394 https://leetcode.com/problems/decode-string/
It may occur "3[a2[c]]"

Either recursion, or find the simplese pattern and expand from inner to outter

Thus, stack will be a good candidate

*/

#include <iostream>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        
        stack<string> stk;
        stringstream cnt;
        
        
        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            
            if (isdigit(c)) {
                cnt << c;
                continue;
            }
            
            if(isAlpha(c)){
                stk.push(string(1, c));
                continue;
            }
            
            if(c == '['){
                stk.push(cnt.str());
                stk.push("[");
                
                // reset count
                cnt.str(std::string());
                continue;
            }
            
            if(c == ']'){
                // start to make string
                stringstream ss;
                while(stk.top().compare("[") != 0){
                    ss << stk.top();
                    //cout << "pop" << stk.top() << endl;
                    stk.pop();
                }
                
                stk.pop(); // pop [
                int count = stoi(stk.top()); // pop number
                stk.pop();
                
                stk.push(makePattern(count, ss.str()));
                
                continue;
            }
            
               
        }
        
        return getDecodedString(stk);
    }
    
    bool isAlpha(char c){
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            return true;
        }
        
        return false;
    }
    
    string getDecodedString(stack<string>& stk){
        stringstream ss;
        
        while(!stk.empty()){
            ss << stk.top();
            stk.pop();
        }        
        
        string rev = ss.str();
        reverse(rev.begin(), rev.end());
        return rev;
    }
                         
                         
    string makePattern(int count, const string& pattern){
        stringstream ss;
        //cout << "make string: count = " << count << ", pattern = " << pattern;
        for(int i = 0; i < count; ++i){
            ss << pattern;
        }
        
        return ss.str();
    }
};