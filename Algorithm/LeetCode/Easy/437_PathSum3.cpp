
/*
https://leetcode.com/problems/path-sum-iii/

DFS to find all possible combinations.
every node need to be checked as a parent node

*/

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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return 0;
        }
             
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);     
    }
    
    // check for a single node
    int dfs(TreeNode* node, int remain){
        if(node == nullptr){
            return 0;
        }
        
        int count = 0;
        
        if(node->val == remain){
            ++count;
        }
        
        // do left right child
        count += dfs(node->left, remain - node->val);
        count += dfs(node->right, remain - node->val);
    
        return count;
    }
    
};