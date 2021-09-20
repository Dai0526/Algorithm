/*
605. Sequence Reconstruction
https://www.lintcode.com/problem/sequence-reconstruction/
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. 
The org sequence is a permutation of the integers from 1 to n, with 1 \leq n \leq 10^41≤n≤10^41
​​Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example 1:
Input:org = [1,2,3], seqs = [[1,2],[1,3]]
Output: false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Example 2:
Input: org = [1,2,3], seqs = [[1,2]]
Output: false
Explanation:
The reconstructed sequence can only be [1,2].

Example 3:
Input: org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Output: true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Example 4:
Input:org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Output:true
[1,2,3]
[[1,2],[1,3]]

Idea

Topological sort
1. build graph
2. set degree, put 0 degree to Queue
2. use a queue
 * need to find unique topological, thus, check queue size, if there are more than 1  item, then return false
 DO TOPOLOGICAL SORT to find a sequences
 
 Then check this unique sequence, if all number matches , then return true
 

*/

#include <map>
#include <set>
#include <queue>

using namespace std;


class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        
        // build graph
        map<int, set<int>> graph; // key value, value is a set of value go to it
        map<int, int> degree; // key number, value degree, use a vector might be better
        
        for(const vector<int>& seq : seqs){
            int seqSize = seq.size();
            
            // from 0 to n - 1, since always check it next
            for(int i = 0; i < seqSize; ++i){
                int num = seq[i];
                graph[num]; //init it if not exist
                
                if(i + 1 >= seqSize){
                    continue;
                }
                
                int next = seq[i + 1];
                // if not found, mean new entry, ++ degree
                if(graph[num].find(next) == graph[num].end()){
                    ++degree[next];
                }
                
                graph[num].insert(next);
            }
 
        }
        
        queue<int> myQueue;
        vector<int> result;
        
        // push all zero degree value to queue
        // 千万不能遍历degree,有些没有degree的根本没有加入set中，所以会有缺失，用vector的话要注意不能init成0
        for(const pair<int, set<int>>& p : graph){
            int val = p.first;
            int deg = degree[val];
            
            if(deg == 0){
                myQueue.push(val);
            }
        }
        
        while(!myQueue.empty()){
            
            int qSize = myQueue.size();
            
            if(qSize != 1){
                return false; // no unique solution
            }
            
            int curr = myQueue.front();
            myQueue.pop();
            result.push_back(curr); // put into result
            
            
            for(int nxt : graph[curr]){
                // find all its next value, -- its degree
                --degree[nxt];
                if(degree[nxt] == 0){
                    myQueue.push(nxt);
                }
            }
        }
        
        
        // check output
        int orgSize = org.size();
        
        if(orgSize != result.size()){
            return false;
        }
        
        for(int i = 0; i < orgSize; ++i){
            if(org[i] != result[i]){
                return false;
            }
        }
        
        return true;
    }
};