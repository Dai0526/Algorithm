/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * https://leetcode.com/problems/inorder-successor-in-bst/
 * 
 * 如果该节点有右子节点, 那么后继是其右子节点的子树中最左端的节点
*  如果该节点没有右子节点, 那么后继是离它最近的祖先, 该节点在这个祖先的左子树内.
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* pSucr = nullptr;
        
        while(root != nullptr && root->val != p->val){
            if(root->val > p->val){
                pSucr = root;
                root = root->left;
            }else{
                root = root->right;
            }
        }
        
        if(root == nullptr){
            return nullptr;
        }
        
        // if it has right child, the successor will be the left most of its right child
        if(root->right != nullptr){
            pSucr = root->right;
            while(pSucr->left != nullptr){
                pSucr = pSucr->left;
            }
        }
           
        return pSucr;
        
    }
};