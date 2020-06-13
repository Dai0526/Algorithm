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


class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> result;
        
        inorderRecursive(root, result);
        
        return result;
        
    }
    
    void inorderRecursive(TreeNode* node, vector<int>& output){
        
        if(node == nullptr){
            return;
        }
        
        inorderRecursive(node->left, output);
        output.push_back(node->val);
        inorderRecursive(node->right, output);
    }


    void inorderStack(TreeNode* node, vector<int>& output){
        
        if(node == nullptr){
            return;
        }
        
        stack<TreeNode*> mySatck;
        TreeNode* dummy = node;
        
        // push all left node from root to stack
        while(dummy != nullptr){
            mySatck.push(dummy);
            dummy = dummy -> left;
        }
        
        while(!mySatck.empty()){
            TreeNode* curr = mySatck.top();
            output.push_back(curr -> val);

            if(curr->right == nullptr){
                mySatck.pop();
                //then check curr's parent node's right child, 
                while(!mySatck.empty() && mySatck.top() -> right == curr){
                    // in order is left, root, right. thus, if top's right is current, mean it is curr root, alreay checked, thus keep pop
                    curr = mySatck.top();
                    mySatck.pop();
                }
                
            }else{
                //if right is not null, then go to its right child, and keep add its left to bottom
                curr = curr->right;
                while(curr != nullptr){
                    mySatck.push(curr);
                    curr = curr->left;
                }
            }
        }
    }
};