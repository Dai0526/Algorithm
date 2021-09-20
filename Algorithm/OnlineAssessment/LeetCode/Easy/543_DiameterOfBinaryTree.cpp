/*
https://leetcode.com/problems/diameter-of-binary-tree/
Recursion

compare max with l + r + 1

return max(left, right) + 1 for current node as a subtree

 */

#include <algorithm>

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int diameter = 0;
        diameterHelper(root, &diameter);
        
        return diameter - 1;
    }
    
    int diameterHelper(TreeNode* root, int* dia){
        if(root == nullptr){
            return 0;
        }
        
        int l = diameterHelper(root->left, dia);
        int r = diameterHelper(root->right, dia);
        
        *dia = max(*dia, l + r + 1);
        
        return max(l, r) + 1;
    }
    
};