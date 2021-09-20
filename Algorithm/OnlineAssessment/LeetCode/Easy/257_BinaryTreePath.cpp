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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;           
        vector<int> path;
        
        dfs(root, path, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, vector<int> path, vector<string>& ans){
        
        if(root == nullptr){
            return;
        }
        
        path.push_back(root->val);
        
        if(root->left == nullptr && root->right == nullptr){
            // root, add current path to ans
            ans.push_back(makePath(path));
            return;
        }
        
        dfs(root->left, path, ans);
        dfs(root->right, path, ans);  
    }
    
    string makePath(const vector<int>& path){
        stringstream ss;
        int n = path.size();
        for(int i = 0; i < n - 1; ++i){
            ss << path[i] << "->";
        }
        
        ss << path[n - 1];
        return ss.str();
    }
};