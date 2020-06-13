/*
https://leetcode.com/problems/reverse-words-in-a-string/

QFA
1. How about space and special character?
2. leading space or trailing space?
*3. Can I use built in stl functions? 
    reverse, split

IDEA:
Reverse -> stack
*/

#include <sstream>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {

        if(s.empty()){
            return s;
        }
        
        vector<string> vec;
        split(vec, s, ' ');
        stringstream ss;
        
        int n = vec.size();       
        if(n == 0){
            return "";
        }
        
        for(int i = n - 1; i > 0; --i){
            ss << vec[i] << " ";                
        }
        
        ss << vec[0];
        
        return ss.str(); 
    }
    
    void split(vector<string>& out, const string& str, const char delimeter){
        stringstream ss(str);  
        string item;
        while(std::getline(ss, item, delimeter)){
            if(item.empty()){
                continue;
            }
            out.push_back(item);
        }
    }
    
};