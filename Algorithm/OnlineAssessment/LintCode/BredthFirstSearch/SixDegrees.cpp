

#include <map>
#include <vector>
#include <queue>

using namespace std;
class Solution {

struct UndirectedGraphNode {
    int label;
        vector<UndirectedGraphNode *> neighbors;
        UndirectedGraphNode(int x) : label(x) {};
};

public:
    /*
     * @param graph: a list of Undirected graph node
     * @param s: Undirected graph node
     * @param t: Undirected graph nodes
     * @return: an integer
     */
    int sixDegrees(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* s, UndirectedGraphNode* t) {
        // Do BFS, go thourh all unvisited neighbors, check if it can reach target
        
        map<UndirectedGraphNode*, int> visited; // node, step
        queue<UndirectedGraphNode*> myQueue;
        
        myQueue.push(s);
        visited[s] = 0;
        
        while(!myQueue.empty()){
            
            UndirectedGraphNode* curr = myQueue.front();
            myQueue.pop();
            
            if(curr == t){
                return visited[t];
            }
            
            for(UndirectedGraphNode* pNode : curr->neighbors){
                if(visited.find(pNode) == visited.end()){
                    // a new node, then add
                    visited[pNode] = visited[curr] + 1;
                    myQueue.push(pNode);                }
            }
            
        }
        
        
        return -1;
        
    }
};