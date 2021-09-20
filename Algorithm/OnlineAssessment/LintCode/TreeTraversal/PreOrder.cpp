/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = NULL;
        }
};


class TreeTraversal {

public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {      
        vector<int> recursive;
        vector<int> stack;
        preOrder_recursive(root, recursive);
        preOrder_stack(root, stack);
        return recursive;    
    }
    
/*
Recursive way, root, left right
Stack: all the way go left, thus push right to the bottom of the stack and deal with it later
*/

    void preOrder_recursive(TreeNode* root, vector<int>& output){
        
        if(root == nullptr){
            return;
        }
        
        output.push_back(root->val);
        preOrder_recursive(root->left, output);
        preOrder_recursive(root->right,output);
    }
    
    void preOrder_stack(TreeNode* root, vector<int>& output){
        
        if(root == nullptr){
            return;
        }
        
        stack<TreeNode*> myStack;
        myStack.push(root);
         
        while(!myStack.empty()){
            TreeNode* curr = myStack.top();
            myStack.pop();
            output.push_back(curr->val);
            // pre order
            if(curr->right != nullptr){
                myStack.push(curr->right);
            } 
            if(curr->left != nullptr){
                myStack.push(curr->left);
            }    
        }
    }
    
};