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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int maxDiff = 0;
        depth(root, maxDiff);
        
        return maxDiff < 2;
        
        return true; 
    }
    
    int depth(TreeNode* root, int& maxDiff){
        
        if(root == nullptr){
            return 0;
        }
        
        int leftDepth = depth(root->left, maxDiff);
        int rightDepth = depth(root->right, maxDiff);
        
        int diff = abs(leftDepth - rightDepth);
        
        if(diff > 1){
            maxDiff = max(maxDiff, diff);
        }
        
        return max(leftDepth, rightDepth) + 1;
        
    }
};