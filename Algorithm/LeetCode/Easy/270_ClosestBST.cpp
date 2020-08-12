/*
https://leetcode.com/problems/closest-binary-search-tree-value/
It is a BST

Everytime compare with root, find closest

if target less than root, go left
if target greater than root, go right 

*/

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        
        while(root != nullptr){
            closest = abs(target - root->val) <= abs(closest - target) ? root->val : closest;
            
            root = target < root->val ? root->left : root->right; 
        }
        
        return closest;
    }
};