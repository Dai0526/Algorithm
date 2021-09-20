
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
      
        if(input.length() == 0) { 
            return 0;
        }
        
        vector<string> items;
        split(input, items, '\n');
        stack<int> parents;
        
        int longestPathLen = 0;
        int currPathLen = 0;
        
        for(string& s : items){
            
            int tabCount = GetNumTab(s);
            
            // reduce down to current level
            while(parents.size() > tabCount) {
                currPathLen -= parents.top();
                parents.pop();
            }
            
            currPathLen += s.size();
            
            if(s.find(".") != string::npos) {
                longestPathLen = max(longestPathLen, currPathLen);
            }
            
            parents.push(s.size() - tabCount);
            currPathLen -= tabCount;
        }
        

        return longestPathLen;
    }
    
    void split(string& s, vector<string>& tks, char delimeter){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delimeter))
        {
            tks.push_back(token);
        }   
    }
    
    int GetNumTab(string& s){
        
        int n = 0;
        for(char c : s){
            if(c != '\t'){
                continue;
            }
            
            ++n;
        }
        
        return n;
    }
    
};