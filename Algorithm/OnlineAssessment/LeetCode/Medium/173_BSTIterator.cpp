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
https://leetcode.com/problems/binary-search-tree-iterator/

In Order Traversal for BST to get a sorted list -> iterator way is to use stack
Then simply iterator for a vector

*/

#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        idx = 0;
        inorder(nodes, root);
    }
    
    void inorder(vector<TreeNode*>& vec, TreeNode* root){
        if(root == nullptr){
            return;
        }
        
        stack<TreeNode*> stk;
        
        TreeNode* temp = root;
        
        // push all left child from root
        while(temp != nullptr){
            stk.push(temp);
            temp = temp->left;
        }
        
        while(!stk.empty()){
            TreeNode* curr = stk.top();
            vec.push_back(curr);
            
            
            if(curr->right == nullptr){
                stk.pop();
                while(!stk.empty() && stk.top()->right == curr){
                    // in order is left, root, right. thus, if top's right is current, mean it is curr root, alreay checked, thus keep pop
                    curr = stk.top();
                    stk.pop();
                }
            }else{
                //if right is not null, then go to its right child, and keep add its left to bottom
                curr = curr->right;
                while(curr != nullptr){
                    stk.push(curr);
                    curr = curr->left;
                }
            }
  
        }   
    }
    
    
    /** @return the next smallest number */
    int next() {
        if(!hasNext()){
            return -1;
        }
        return (nodes[idx++])->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(idx < nodes.size()){
            return true;
        }
        
        return false;
    }
    
private:
    vector<TreeNode*> nodes;
    int idx;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */