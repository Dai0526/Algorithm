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
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        getPathSum(root, 0, total);
        
        return total;
        
    }
    
    void getPathSum(TreeNode* node, int path, int& total){
        
        int val = node->val;
        path = path * 2 + val;
        
        if(node->left == nullptr && node->right == nullptr){
            total += path;
        }
        
        if(node->left != nullptr){
            getPathSum(node->left, path, total);
        }
        
        if(node->right != nullptr){
            getPathSum(node->right, path, total);
        }
    }
};