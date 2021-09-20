/*
618. Search Graph Nodes
https://www.lintcode.com/problem/search-graph-nodes/
Given a undirected graph, a node and a target, return the nearest node to given node which value of it is target, return NULL if you can't find.
There is a mapping store the nodes' values in the given parameters.

Example 1:

Input:
{1,2,3,4#2,1,3#3,1,2#4,1,5#5,4}
[3,4,5,50,50]
1
50
Output: 4
Explanation:
2------3  5
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      1 --4
Give a node 1, target is 50

there a hash named values which is [3,4,10,50,50], represent:
Value of node 1 is 3
Value of node 2 is 4
Value of node 3 is 10
Value of node 4 is 50
Value of node 5 is 50

Return node 4
Example 2:
Input:
{1,2#2,1}
[0,1]
1
1
Output: 2
Notice
It's guaranteed there is only one available solution

Idea：
there is a graph, need to find shortest path to the target value

BFS, push check node, if not, then push all its neighbors to queue,

Need a set to remove duplicated cases

*/

#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;


class Solution {
  //Definition for Undirected graph.
  struct UndirectedGraphNode {
    int label;    
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
}; 


public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        
        // check edge cases...
        
        set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> myQueue;
        
        myQueue.push(node);
        visited.insert(node);
        
        
        while(!myQueue.empty()){
            
            UndirectedGraphNode* curr = myQueue.front();
            myQueue.pop();
            
            // check 
            if(values[curr] == target){
                return curr;
            }
            
            for(UndirectedGraphNode* ugNode : curr->neighbors){
                if(visited.find(ugNode) != visited.end()){
                    continue;
                }
                
                myQueue.push(ugNode);
                visited.insert(ugNode);
                
            }
        }
        
        
        return nullptr;
    }
};