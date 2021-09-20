/*
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

pre order: root->left->right
in order: left ->root->right

1. Construct it from root, thus first element of preorder list is the root.
2. The root from preOrder list, divided inorder list two left and right subtree

Recursively do it 

Note that root idx need to pass by reference cause each recursive run will change it and 
it affect next recursion.
*/

#include <unordered_map>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // use inorder list to build tree, preorder for assisstant.
        unordered_map<int, int> idxMap; // value, idx in inorder
        int idx = 0;
        for(int n : inorder){
            idxMap[n] = idx;
            ++idx;
        }
        
        // reset and pass to function
        idx = 0;
        return treeBuilder(0, inorder.size() - 1, preorder, inorder, idxMap, idx);
    }
    
    TreeNode* treeBuilder(int l, int r, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& idxMap, int& preRootIdx){
        if(l > r){
            return nullptr;
        }
  
        // get root and create root node
        int rootVal = preorder[preRootIdx];
        TreeNode* root = new TreeNode(rootVal);
        
        // To split into two subtree, get idx for left and right from inorder list
        int inRootIdx = idxMap[rootVal];
        
        ++preRootIdx;
        
        // get left and right node (subtree)
        root->left = treeBuilder(l, inRootIdx - 1, preorder, inorder, idxMap, preRootIdx);
        root->right = treeBuilder(inRootIdx + 1, r, preorder, inorder, idxMap, preRootIdx);
        return root;
    }
};