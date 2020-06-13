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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
#include <vector>
#include <stack>
using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int val) {
            this->val = val;
            this->left = this->right = nullptr;
        }
};

class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
   BSTIterator(TreeNode * root) {
        // do intialization if necessary
        LoadTreeInOrder(root);
        m_nCurrIdx = m_treeVec.size() > 0 ? 0 : -1;
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        int size = m_treeVec.size();

        return (m_nCurrIdx < size) && (size > 0) ;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        return m_treeVec[m_nCurrIdx++];
        
    }
    
    void LoadTreeInOrder(TreeNode* root){
        TreeNode* curr = root;
        stack<TreeNode*> myStack;
        
        while(curr != nullptr){
            myStack.push(curr);
            curr = curr->left;
        }
        
        
        while(!myStack.empty()){
            
            TreeNode* node = myStack.top();
            myStack.pop();

            
            m_treeVec.push_back(node);
            
            if(node-> right != nullptr){
                node = node -> right;
                while(node != nullptr){
                    myStack.push(node);
                    node = node -> left;
                }
            }
        }
        
    }
    
private:
    vector<TreeNode *> m_treeVec;
    int m_nCurrIdx;
};