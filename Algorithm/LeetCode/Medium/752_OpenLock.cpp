/*
https://leetcode.com/problems/open-the-lock/
BFS each time 8 changes

*/

#include <iostream>
#include <set>
#include <vector>
#include <queue>


class Solution {
    
private:

    
public:
    int openLock(vector<string>& deadends, string target) {
        
        // convert deadend to set for fast search
        set<string> deadLock(deadends.begin(), deadends.end());
        
        set<string> tried;
        
        queue<string> q;
        q.push("0000");
        tried.insert("0000");
        
        int count = 0;
        
        while(!q.empty()){
            int qsize = q.size();
            
            for(int i = 0; i < qsize; ++i){
                
                string last = q.front();
                q.pop();
                
                if(last.compare(target) == 0){
                    return count;
                }
                
                if(deadLock.find(last) != deadLock.end()){
                    continue; // skip if it is a deadlack
                }
                
                for(int j = 0; j < 4; ++j){
                    handleNext(j, 1, last, q, tried);
                    handleNext(j, -1, last, q, tried);
                }
            }
            
            ++count;
            
        }
        
        return -1;
    }
    
    void handleNext(int idx, int offset, string curr, queue<string>& q, set<string>& visited){
        
        //cout << "curr = " << curr;
        curr[idx] = static_cast<char>((curr[idx] - '0' + 10 + offset) % 10) + '0';
        //cout << ", next = " << curr << endl;
        if(visited.find(curr) != visited.end()){
            return;
        }
        
        q.push(curr);
        visited.insert(curr);
    }
};