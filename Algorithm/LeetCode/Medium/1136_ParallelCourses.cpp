class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // build graph and topological sort
        vector<int> degrees(n, 0);
        map<int, vector<int>> graph;
        
        // build graph
        for(const vector<int>& rel : relations){
            int preReq = rel[0] - 1;
            int courseNum = rel[1] - 1;
            
            // treat as directed graph [1,0], direction is 0 -> 1, so 1's degree += 1
            graph[preReq].push_back(courseNum);
            ++degrees[courseNum];
        }
        
        
        queue<int> myQueue;
        
        for(int i = 0; i < n; ++i){
            if(degrees[i] == 0){
                myQueue.push(i);
            }
        }
        
        int nSem = 0;
        int count = 0;
        
        // do a topological sort
        while(!myQueue.empty()){         
            ++nSem;
            int qsize = myQueue.size();
            
            for(int i = 0; i < qsize; ++i){
                int courseIdx = myQueue.front();
                myQueue.pop();
                ++count;
                for(int i : graph[courseIdx]){
                    degrees[i] -= 1;
                
                    if(degrees[i] == 0){
                        myQueue.push(i);
                    }
                }
            }
        }
        
        if(count == n){
            return nSem;
        }
        
        return -1;
    }
};