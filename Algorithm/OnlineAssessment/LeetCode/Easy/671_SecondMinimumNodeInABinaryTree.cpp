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
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long long minVal = root->val;
        long long ans = numeric_limits<long>::max();
        dfs(root, minVal, ans);
        
        return ans == numeric_limits<long>::max() ? -1 : ans;
         
    }
    
    void dfs(TreeNode* root, long long min, long long& ans){
        if(root == nullptr){
            return;
        }
        
        if(min < root->val && root->val < ans){
            ans = root->val;
        }else if(min == root->val){
            dfs(root->left, min, ans);
            dfs(root->right, min, ans);
        }     
    }
};