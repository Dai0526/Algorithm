/*
https://leetcode.com/problems/invert-binary-tree/
BFS level order traversal
reverse each level 
*/

#include <queue>
using namespace std;

class Solution {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int qSize = q.size();
            
            for(int i = 0; i < qSize; ++i){
                TreeNode* curr = q.front();
                q.pop();
                
                TreeNode* temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
                
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