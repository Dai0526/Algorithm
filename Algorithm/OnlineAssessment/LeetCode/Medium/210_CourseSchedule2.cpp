/*
https://leetcode.com/problems/course-schedule-ii/

Build a graph about course prerequsit
Do Topological sort.

*/

#include <queue>
#include <map>
#include <vector>

using namespace std;

class Solution {
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
        // build a graph
        vector<int> degrees(numCourses, 0);
        map<int, vector<int>> graph;
        
        for(const vector<int>& vec : prerequisites){
            int course = vec[0];
            int preReq = vec[1];
            
            graph[preReq].push_back(course);
            ++degrees[course];
        }
        
        // push all zero degree course to queue
        queue<int> myQueue;
        for(int i = 0; i < degrees.size(); ++i){
            if(degrees[i] == 0){
                myQueue.push(i);
            }
        }
        
        vector<int> path;
        int count = 0;
        
        while(!myQueue.empty()){
            int courseId = myQueue.front();
            myQueue.pop();
            path.push_back(courseId);
            ++count;
            
            for(int i : graph[courseId]){
                --degrees[i];  
                if(degrees[i] == 0){
                    myQueue.push(i);
                }
            }
        }
        
        if(count == numCourses){
            return path;
        }
        
        return vector<int>();
    }
};