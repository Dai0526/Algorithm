/*
https://leetcode.com/problems/validate-binary-search-tree/

QFA: how about equal? goes left or right

Several ways to do it.
1. divide and conqur, recursion    
2. Inorder traversal, before > after
3. DFS

*/

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
    bool isValidBST(TreeNode* root) {
        return isValidBSTInOrder(root);
        //return isValidBSTHelper(root, numeric_limits<long long>::min(), numeric_limits<long long>::max());      
    }
    
    bool isValidBSTInOrder(TreeNode* root){
        stack<TreeNode*> myStack;
        TreeNode* dummy = root;
        
        while(dummy != nullptr){
            myStack.push(dummy);
            dummy = dummy->left;
        }
        
        long long pre = numeric_limits<long long>::min(); 

        while(!myStack.empty()){
            TreeNode* curr = myStack.top();

            if(pre >= curr->val){
                return false;
            }
            
            pre = curr->val;
            
            if(curr->right == nullptr){
                myStack.pop();
                while(!myStack.empty() && myStack.top() -> right == curr){
                // in order is left, root, right. thus, if top's right is current, mean it is curr root, alreay checked, thus keep pop
                    curr = myStack.top();
                    myStack.pop();
                }
            }else{
                curr = curr -> right;
                while(curr != nullptr){
                    myStack.push(curr);
                    curr = curr->left;
                }                
            }   
        }
        
        return true;
    }
    
    bool isValidBSTHelper(TreeNode* root, long long min, long long max){
        // exit when all sub tree is valid
        if(root == nullptr){
            return true;
        }
        
        if(root->val <= min || root->val >= max){
            return false;
        }
        
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
        
    }
};