/*
https://leetcode.com/problems/simplify-path/
Do from highest directory level to down

use vector to simulate stack -> push_back, pop_back

Split by using istringstream with getline(iss, token, dilemeter);

loop over all tokens

3 cases:
1. empty '' or '.', continue
2. "..", pop one out if not emoty
3. push to vector

then buil string join with '/'

if final string is empty, add '/' at back

*/
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> vec;
        split(path, vec, '/');
        
        // use a stack to hold all items
        vector<string> tks;
        
        for(const string& p : vec){
            if(p.compare(".") == 0 || p.empty()){
                continue;
            }
            
            if(p.compare("..") == 0){
                if(!tks.empty()){
                    tks.pop_back();
                }
            }else{
                tks.push_back(p);
            }
        }
        
        stringstream ss;
        
        for(string& s : tks){
            ss << "/" << s;
        }
        
        
        if(ss.str().empty()){
            ss << "/";            
        }
        
        return ss.str();
    }
    
    void split(string& s, vector<string>& vec, char delimeter){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delimeter))
        {
            vec.push_back(token);
        }
    }
};