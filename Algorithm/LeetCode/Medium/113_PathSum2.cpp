/*
DFS + backtracking
https://leetcode.com/problems/path-sum-ii/

 */
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        
        if(root == nullptr){
            return res;
        }
        
        vector<int> path;        
        AddPath(root, sum, path, res);
        
        return res;        
        
    }
    
    
    void AddPath(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& res){
        
        if(node->left == nullptr && node->right == nullptr && remain == node->val){
            // leaf
            path.push_back(node->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        
        int curr = node->val;
        
        path.push_back(curr);
        
        if(node->left != nullptr){
            AddPath(node->left, remain - curr, path, res);
        }
        
        if(node->right != nullptr){
            AddPath(node->right, remain - curr, path, res);
        }
        
        path.pop_back();
    }
    
};

