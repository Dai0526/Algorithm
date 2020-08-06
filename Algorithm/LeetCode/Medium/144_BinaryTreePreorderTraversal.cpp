/*
https://leetcode.com/problems/binary-tree-preorder-traversal/

Use stack to do DFS iteratively.
    root -> left -> right

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        if(root == nullptr){
            return ans;
        }
        
        stk.push(root);
        
        while(!stk.empty()){
            
            TreeNode* curr = stk.top();
            stk.pop();
            
            ans.push_back(curr->val);
            
            if(curr->right != nullptr){
                stk.push(curr->right);
            }
            
            if(curr->left != nullptr){
                stk.push(curr->left);
            }
                        
        }
        
        return ans;
    }
    
    void preorderRec(TreeNode* node, vector<int>& vec){
        if(node == nullptr){
            return;
        }
        
        vec.push_back(node->val);
        preorderRec(node->left, vec);
        preorderRec(node->right, vec);
    }
};