/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/
Recursively PreOrder 
    a. Vector<vector<int>> paths
        Find all path, them add up
    b. Vector<int> path 
        Sum each path and when it is left, add to vector 
Then Sum up 

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
    int sumNumbers(TreeNode* root) {
        
        vector<int> paths;
        preorder(root, 0, paths);
        
        int sum = 0;
        
        for(int n : paths){
            sum += n;
        }
        
        return sum;
    }
    
    void preorder(TreeNode* root, int n, vector<int>& path){
        if(root == nullptr){
            return;
        }
        
        n = 10 * n + root->val;
        
        // if it is leaf, push to path
        if(root->left == nullptr && root->right == nullptr){
            path.push_back(n);
        }
    
        preorder(root->left, n, path);
        preorder(root->right, n, path);  
    }
};