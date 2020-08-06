/*
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Recursion

recursively add left node to be the right of root, and add right to its flattened 
last node's right

递归出口
1. node == nullptr, return nullptr
2. node is leaf, return node

leftTail = Recursively do left
rightTail = Recursively do right

if leftTail == nullptr
    leftTail->right = node->right
    node->right = node->left;
    node->left = nullptr;

if right not null, return rightTail
else return leftTail

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
    void flatten(TreeNode* root) {
        flattenRec(root);    
    }
    
    TreeNode* flattenRec(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        
        // leaf
        if(node->left == nullptr && node->right == nullptr){
            return node;
        }
        
        TreeNode* leftTail = flattenRec(node->left);
        TreeNode* rightTail = flattenRec(node->right);
        
        if(leftTail != nullptr){
            leftTail->right = node->right;
            node->right = node->left;
            node->left = nullptr;
        }
        
        // return right most 
        return rightTail == nullptr ? leftTail : rightTail;
    }
};