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
https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
inorder ->  left, root, right
postorder-> left, right ,root

for each recursion
1. the last node of postorder is the root of current subtree
2. find that node in inorder vect, we get left and right subtree
3. Then we can get the left and right subtree's index in post order vec.
e.g.
if the root idx in inorder is k
then in inorder left subtree [0,k-1] right [k+1, 9]

postorder:
left [post_strt, post_strt + (k - 1 - in_start)], 
right [post_end - 1 - (in_end - i - 1), post_end - 1]

*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    TreeNode* dfs(const vector<int>& inorder, const vector<int>& postorder, int inl, int inr, int postl, int postr){
        if(inl > inr || postl > postr){
            return nullptr;
        }
        
        int rootVal = postorder[postr];
        TreeNode* root = new TreeNode(rootVal);
        cout << "root Val " << rootVal <<endl;
        int inRootIdx = getIdx(inorder, rootVal);
        
        root->left = dfs(inorder, postorder, inl, inRootIdx - 1, postl, postl + inRootIdx - inl - 1);
        root->right = dfs(inorder, postorder, inRootIdx + 1, inr, postr - inr + inRootIdx, postr - 1);
        
        return root;
    }
    
    int getIdx(const vector<int>& vec, int val){
        for(int i = 0; i < vec.size(); ++i){
            if(vec[i] == val){
                return i;
            }
        }
        
        return -1; // won't happend in this problem
    }
};