/*
137. Clone Graph
https://www.lintcode.com/problem/clone-graph/
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors. Nodes are labeled uniquely.
You need to return a deep copied graph, which has the same structure as the original graph, and any changes to the new graph will not have any effect on the original graph.

Example1
Input:
{1,2,4#2,1,4#4,1,2}
Output: 
{1,2,4#2,1,4#4,1,2}
Explanation:
1------2  
 \     |  
  \    |  
   \   |  
    \  |  
      4   
Clarification
How we serialize an undirected graph: http://www.lintcode.com/help/graph/

Notice
You need return the node with the same label as the input node.

思路： 广度优先
一个队列用于记录每一个需要搜索的节点
一个map，记录各个点

克隆source点 到cloned， 加入队列，进行Bfs
从Queue里pop一个点node出来进行广搜，把该点加入到map里进行记录
看node的每一个neighbor
如果这个neighbor没有被作为主点搜索过，
    1. 在map中新增一个记录
    2. 加入Queue进行搜索
    3. 并把这个neighbor加入到node的neighbor列表中
如果这个neighbor被搜索过，
    1. 把这个neighbor加入到node的neighbor列表中

最后返回cloned
*/

#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {

 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
 };


public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if(node == nullptr){
            return nullptr;
        }
        
        // use a map to track visited node
        map<int, UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> myQueue;
        
        UndirectedGraphNode* cloned = new UndirectedGraphNode(node->label);
        visited[node->label] = cloned;
        
        myQueue.push(node);
        
        while(!myQueue.empty()){
            
            UndirectedGraphNode* current = myQueue.front();
            myQueue.pop();
            
            for(UndirectedGraphNode* nb : current -> neighbors){
                
                int nbLabel = nb -> label;
               
                // if it is not in recorded map, then add it to map, add it to the neighbor of current node
                if(visited.find(nbLabel) == visited.end()){
                    visited[nbLabel] = new UndirectedGraphNode(nbLabel);
                    myQueue.push(nb);
                    visited[current->label]->neighbors.push_back(visited[nbLabel]);
                    
                }else{
                    visited[current->label]->neighbors.push_back(visited[nbLabel]);
                }
                
                
            }    
        }
        
        return cloned;
    }
};
