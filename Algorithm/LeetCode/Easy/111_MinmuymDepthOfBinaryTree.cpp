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
    int minDepth(TreeNode* root) {

        return depth(root);
    }
    
    int depth(TreeNode* root){
        
        if(root == nullptr){
            return 0;
        }
        
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }
        
        int leftDepth = numeric_limits<int>::max();
        if(root->left != nullptr){
            leftDepth = depth(root->left);
        }
        
        int rightDepth = numeric_limits<int>::max();
        if(root->right != nullptr){
            rightDepth = depth(root->right);
        }
        
        return min(leftDepth, rightDepth) + 1;    
    }
};