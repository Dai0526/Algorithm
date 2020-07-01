/*
Toplogical Sort - BFS

build graph first
map of courses
vector of degree

push all zero degree edge to queue,
do bfs, remove edges

check if there is still edge left -> cycle

*/

#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        unordered_map<int, vector<int>> courses; // course num, degree
        vector<int> degree(numCourses, 0);
        
        for(const vector<int>& vec : prerequisites){
            int cid = vec[0];
            int pre = vec[1];
            
            courses[pre].push_back(cid);
            ++degree[cid];
        }
        
        // add 0 degree course to queue
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(degree[i] == 0){
                q.push(i);
            }
        }
        
        // do topological sort
        int count = 0; // valid courses
        while(!q.empty()){
            int prereq = q.front();
            q.pop();
            ++count;
            
            for(int next : courses[prereq]){
                --degree[next];
                if(degree[next] == 0){
                    q.push(next);
                }
            }
        }
        
        return count == numCourses;
        
    }
};