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
https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

Several working solution
1. In-Order traversal -> sorted array -> two pointer for two sum problem.
2. BFS and hashset

*/

#include <queue>
#include <set>

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
    bool findTarget(TreeNode* root, int k) {
        set<int> nums;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(nums.find(k - node->val) != nums.end()){
                return true;
            }
            
            nums.insert(node->val);

            // add left and right child
            if(node->left != nullptr){
                q.push(node->left);
            }
            
            if(node->right != nullptr){
                q.push(node->right);
            }
            
        }
        
        return false;
    }
};