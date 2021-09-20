/*
create a size n vector
use a stack to store info, 
    1. if 'start'
        a. push tid to stack
        b. calculate time, add to vector where top item in stack
        c. store this timestamp
    2. else 'end'
        a. calculate time with the top item in stack --- that's promising, end tid must match top tid in stack
        b. pop stack
        c. store timestamp
*/


#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> t(n,0);
        stack<int> tids;
        
        vector<string> tks = split(logs[0], ':');
        int tid = stoi(tks[0]);
        int timestamp = stoi(tks[2]);
        
        tids.push(tid);
        t[tid] = timestamp;
        
        int prevTime = timestamp;
        
        for(int i = 1; i < logs.size(); ++i){
            tks = split(logs[i], ':');
            tid = stoi(tks[0]);
            timestamp = stoi(tks[2]);
            
            if(tks[1].compare("start") == 0){
                if(!tids.empty()){
                    t[tids.top()] += timestamp - prevTime;
                }
                
                tids.push(tid);
                prevTime = timestamp;
            }else{
                t[tids.top()] += timestamp - prevTime + 1;
                tids.pop();
                prevTime = timestamp + 1;
            }    
            
        }
        
        return t;
    }
    
     vector<string> split(string& s, char delimeter){
        std::istringstream iss(s);
        string token;
        
        vector<string> tks;
        
        while (std::getline(iss, token, delimeter))
        {
            tks.push_back(token);
        }
        
        return tks;
    }
    
};