/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
https://leetcode.com/problems/merge-two-binary-trees/solution/

Recursion 
Use 2 recursions.
1. Recursivly merge two tree
2. If one node is nullptr, recursively copy another node.

*/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr){
            return t2;
        }
        
        if(t2 == nullptr){
            return t1;
        }
        
        TreeNode* curr = new TreeNode(t1->val + t2->val);
        curr->left = mergeTrees(t1->left, t2->left);
        curr->right = mergeTrees(t1->right, t2->right);
        
        return curr;
    }
    
    // recursively copy a tree from node
    TreeNode* copySubtree(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        
        TreeNode* curr = new TreeNode(node->val);
        curr->left = copySubtree(node->left);
        curr->right = copySubtree(node->right);
        
        return curr;
    } 
};