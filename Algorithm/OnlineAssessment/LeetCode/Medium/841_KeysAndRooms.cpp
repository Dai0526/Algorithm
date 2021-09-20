/*
BFS
https://leetcode.com/problems/keys-and-rooms/
*/
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int nRoom = rooms.size();
        unordered_set<int> visited;
        queue<int> q;
        
        // init
        for(int n : rooms[0]){
            q.push(n);
        }
        
        visited.insert(0);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            visited.insert(curr);
            
            //add aviliable rooms
            for(int n : rooms[curr]){
                if(visited.find(n) == visited.end()){
                    q.push(n); 
                }
            }
        }
         
        return nRoom == visited.size();
    }
};