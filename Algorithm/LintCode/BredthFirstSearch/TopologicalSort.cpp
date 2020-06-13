/*
127. Topological Sorting
https://www.lintcode.com/problem/topological-sorting/
Given an directed graph, a topological order of the graph nodes is defined as follow:

For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.

Example
For graph as follow:
The topological order can be:
[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...
Challenge: Can you do it in both BFS and DFS?

Clarification
Learn more about representation of graphs

Notice
You can assume that there is at least one topological order in the graph.
思路：
计算入度，建立一个map（其他数据结构也可以）
根据入度，为0的加入队列中
然后去除入度为0的节点，更新每一个neighborde入度
*/

#include <vector>
#include <map>
#include <queue>

using namespace std;

class Solution {

struct DirectedGraphNode {
      int label;
      vector<DirectedGraphNode *> neighbors;
      DirectedGraphNode(int x) : label(x) {};
};

public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        
        // 1. build a graph, and get node's degree
        map<DirectedGraphNode*, int> degree;    
        for(DirectedGraphNode* node : graph){
            // go through its neighbors
            for(DirectedGraphNode* nb : node->neighbors){
                // a -> b means b is a neighbor of a, thus b has someone ponint to it, degree += 1
                if(degree.find(nb) == degree.end()){
                    degree[nb] = 1;
                }else{
                    degree[nb] += 1;
                }
            }
        }
        
        queue<DirectedGraphNode*> myQueue;
        vector<DirectedGraphNode*> out;

        // put all zero degree node into map for topological sort
        for(DirectedGraphNode* node : graph){
            if(degree[node] == 0){
                myQueue.push(node);
                
            }
        }
      
        while(!myQueue.empty()){
            
            DirectedGraphNode* node = myQueue.front();
            myQueue.pop();
            out.push_back(node);
            //one node removed, thoese next nodes degree - 1
            for(DirectedGraphNode* nb : node->neighbors){
                degree[nb] --;
                
                if(degree[nb] == 0){
                    myQueue.push(nb);
                }
                
            }
            
        }    

        return out;    
    }
};