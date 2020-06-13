/**
448. Inorder Successor in BST
https://www.lintcode.com/problem/inorder-successor-in-bst/
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.
If the given node has no in-order successor in the tree, return null.

Example 1:
Input: {1,#,2}, node with value 1
Output: 2
Explanation:
  1
   \
    2

Example 2:
Input: {2,1,3}, node with value 1
Output: 2
Explanation: 
    2
   / \
  1   3


Challenge
O(h), where h is the height of the BST.

Notice
It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)
 
 
 
 * Loop root until found the P node or NULL
 * If p node is found
 *  1. has right child, in order successor must in its right subtree's left most child
 *  2. no right child, then its parent node is the success
 * else
 *  return NULL

 * 
 */

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
class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        
        TreeNode* temp;
        
        while(root != nullptr && root != p){
            if(root->val >= p->val){
                temp = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        
        if(root == nullptr){
            return nullptr;
        }
        
        if(root->right == nullptr){
            return temp;
        }
        
        root = root->right;
        // find left most child
        while(root->left != nullptr){
            root = root->left;
        }
        
        return root;
    }
};