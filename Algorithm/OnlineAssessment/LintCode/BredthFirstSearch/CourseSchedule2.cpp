#include <vector>
#include <queue>
#include <map>

using namespace std;
class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // 1. build a graph
        vector<int> degrees(numCourses, 0);
        map<int, vector<int>> graph;
        
        // build graph
        for(const pair<int, int>& p : prerequisites){
            int courseNum = p.first;
            int preReq = p.second;
            
            // treat as directed graph [1,0], direction is 0 -> 1, so 1's degree += 1
            graph[preReq].push_back(courseNum);
            ++degrees[courseNum];
        }
        
        
        queue<int> myQueue;
        
        // push all 0 degree course Number to a std::queue
        for(int i = 0; i < numCourses; ++i){
            if(degrees[i] == 0){
                myQueue.push(i);
            }
        }
        
        
        // need a count to see if there is a topological sortt
        int count = 0;
        vector<int> out;
        
        // do a topological sort
        while(!myQueue.empty()){
            
            int courseId = myQueue.front();
            myQueue.pop();
            out.push_back(courseId);
            ++count;
            
            for(int i : graph[courseId]){
                degrees[i] -= 1;
                
                if(degrees[i] == 0){
                    myQueue.push(i);
                }
            }
        }
        
        if(count == numCourses){
            //there is a possible way to finish all courses
            return out;
        }
        
        
        return vector<int>();
    }
};