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
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return vector<int>();
        }    
        
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        TreeNode* curr = root;
        
        while(curr != nullptr || !nodeStack.empty()){
            while(curr != nullptr){
                nodeStack.push(curr);
                curr = curr->left;
            }
            
            curr = nodeStack.top();
            nodeStack.pop();
            
            ans.push_back(curr->val);
            curr = curr->right;
        }    
        
        return ans; 
    }
    
    
    vector<int> inorderTraversal2(TreeNode* root) {
        if(root == nullptr){
            return vector<int>();
        }    
        
        vector<int> ans;
        stack<TreeNode*> nodeStack;
        
        while(root != nullptr){
            nodeStack.push(root);
            root = root->left;
        }
        
        while(!nodeStack.empty()){
            TreeNode* curr = nodeStack.top();
            ans.push_back(curr->val);
            
            if(curr->right == nullptr){
                nodeStack.pop();
                while(!nodeStack.empty() && nodeStack.top()->right == curr){
                    curr = nodeStack.top();
                    nodeStack.pop();
                }
            }else{
                curr = curr->right;
                while(curr != nullptr){
                    nodeStack.push(curr);
                    curr = curr->left;
                }
            }
        }
        
        return ans; 
    }
    
    
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    
};