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

bottom up recursion
1. find the left most node as its new root

2. back its partent so you can access all 3 relevent nodes
y->left = z
y->right = x
x->left = nullptr
x->right = nullptr

*/
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* newRoot = root; // the last recursion will set it to leftmost
        
        if(root != nullptr && root->left != nullptr){
            // keep update new root to the left most
            newRoot = upsideDownBinaryTree(root->left);
            
            //second bottom level
            root->left->left = root->right;
            root->left->right = root;
            
            root->left = nullptr;
            root->right = nullptr;   
        }
        
        return newRoot;
    }
};