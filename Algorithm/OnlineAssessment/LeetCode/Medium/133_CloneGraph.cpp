/*
https://leetcode.com/problems/clone-graph/

BFS - 
A map to store newly cloned node
A queue for src nodes that need to be cloned.

*/

#include <vector>
#include <map>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:

    Node* cloneGraph_DFS(Node* node) {      
        map<int, Node*> graph;       
        return dfs(node, graph);     
    }
    
    Node* dfs(Node* node, map<int, Node*>& graph){
        if(node == nullptr){
            return nullptr;
        }
        
        if(graph.find(node->val) != graph.end()){
            return graph[node->val];
        }
        
        Node* temp = new Node(node->val);
        graph[temp->val] = temp;
        
        for(Node* nbh : node->neighbors){
            Node* clone = dfs(nbh, graph);
            temp->neighbors.push_back(clone);
        }
        
        return temp;
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        
        map<int, Node*> visited; // target node map
        queue<Node*> myQueue; // src node 
        
        
        Node* cloned = new Node(node->val);
        visited[cloned->val] = cloned;
        
        myQueue.push(node);
        
        while(!myQueue.empty()){
            Node* curr = myQueue.front();
            myQueue.pop();
            for(Node* nbr : curr->neighbors){
                int value = nbr->val;
                
                if(visited.find(value) == visited.end()){
                    // it is a new node,    
                    Node* temp = new Node(value); //clone it
                    visited[value] = temp; // mark visited,
                    myQueue.push(nbr);//add to queue,
                    visited[curr->val]->neighbors.push_back(temp);//push it to curr's neighbor
                }else{
                    // if it is a node in record, then add it to neighbor's list
                    visited[curr->val]->neighbors.push_back(visited[value]);//push it to curr's neighbor   
                }
                
            }
        }

        return cloned;
    }
};