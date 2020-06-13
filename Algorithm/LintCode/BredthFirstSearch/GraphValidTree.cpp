/*

178. Graph Valid Tree
https://www.lintcode.com/problem/graph-valid-tree
Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:
Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
Output: true.

Example 2:
Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
Output: false.

Notice
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


build a graph, use bfs to go for all node

a Valid tree is 
1. No circle -> no repeat 
2. All node connected -> total edge = # node - 1

每次检查一个node, 看他的所有neighbor n
如果没有检查过，加入Queue, 在n的neighbor去掉这个node


*/
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        //build a graph
        
        set<int> visited;
        map<int, set<int>> graph;
        
        
        for(const vector<int>& pair : edges){
            
            int fst = pair[0];
            int snd = pair[1];
            
            graph[fst].insert(snd);
            graph[snd].insert(fst);
            
        }
        
        queue<int> myQueue;
        myQueue.push(0);
        visited.insert(0);
        
        while(!myQueue.empty()){
            
            int curr = myQueue.front();
            myQueue.pop();
            
            for(int n : graph[curr]){
                
                if(visited.find(n) != visited.end()){
                    // repeat, there is a circle,
                    return false;
                }
                
                myQueue.push(n);
                visited.insert(n);
                graph[n].erase(curr);
            }
            
        }
        
        return visited.size() == n;
        
    }
};