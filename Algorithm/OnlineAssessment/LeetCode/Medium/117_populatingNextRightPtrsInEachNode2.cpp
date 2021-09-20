/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
117. Populating Next Right Pointers in Each Node II

BFS - level order traversal
Solution is the same as 116

*/

#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int qsize = q.size();
            
            for(int i = 0; i < qsize; ++i){
                Node* curr = q.front();
                q.pop();
                
                // skip last one in this level
                if(i < qsize - 1){
                    curr->next = q.front();
                }
                
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
        
        }
        
        return root;   
    }
};