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

  struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

public:

    TreeNode* searchBST_iter(TreeNode* root, int val) {
     
        while(root != nullptr){
            
            if(root->val > val){
                root = root->left;
            }else if(root->val < val){
                root = root->right;
            }else{
                return root;
            }
        }
        
        return nullptr;
        
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == nullptr){
            return root;
        }
        
        if(root->val == val){
            return root;
        }
        
        if(root->val < val){
            return searchBST(root->right, val);
        }

        return searchBST(root->left, val);
    }
};