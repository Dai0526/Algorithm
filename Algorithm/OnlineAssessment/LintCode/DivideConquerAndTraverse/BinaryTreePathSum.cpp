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
 */
#include <vector>
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
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        vector<vector<int>> paths;
        if(root == nullptr){
            return paths;
        }
        
        vector<int> p;
        dfs(root, p, 0, target, paths);
        
        return paths;
    }
    
    void dfs(TreeNode* node, vector<int>& path, int sum, int target, vector<vector<int>>& result){
        
        if(node == nullptr){
            return;
        }
        
        path.push_back(node -> val);
        sum += node->val;
        
        if(node->left == nullptr && node->right == nullptr && sum == target){
            result.push_back(path);
        }
        
        dfs(node->left, path, sum, target, result);

        dfs(node->right, path, sum, target, result);
        path.pop_back();
        sum -= node->val;

    }
    
};