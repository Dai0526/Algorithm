/**
 * Definition for a binary tree node.

 */


/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
1. 理解题意！
不是从root开始的path，也不是上往下的path，而是connected path!
所以要计算每一个left subtree 和right subtree的和
对于每一个node来说，path sum是 l + r + node->val
但是该点作为母点的值是 max(l, r) + node->val

recursion 由底向上

所以子问题是得到
    a. 左子树的最大和（或者不取=0）= max(getMaxPath(left), 0)
    b. 右子树的最大和（或者不取=0）= max(getMaxPath(right), 0)

更新最大值 
    *maxsum = max(*maxsum, l + r + node->val);

返回这个点作为子节点作为子节点的最大值
    return node->val + max(l, r);
*/

#include <algorithm>
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
    
    int maxPathSum(TreeNode* root) {  
        int maxsum = numeric_limits<int>::min();
        getMaxPath(root, &maxsum);
        return maxsum;
    }
       
    int getMaxPath(TreeNode* node, int* maxsum){
        if(node == nullptr){
            return 0;
        }
        
        int l = max(getMaxPath(node->left, maxsum), 0);
        int r = max(getMaxPath(node->right, maxsum), 0);
        
        *maxsum = max(*maxsum, l + r + node->val);
        return node->val + max(l, r);
    }
    
    // 从root出发一直到底的做法，与题目要求不同
    int maxPathSum_fromRoot(TreeNode* root) {  
        int maxsum = numeric_limits<int>::min();
        dfs(root, 0, &maxsum);
        return maxsum;
    }
    
    void dfs(TreeNode* node, int current, int* maxsum){
        if(node == nullptr){
            *maxsum = max(current, *maxsum);
            return;
        }
        
        current += node->val;
        
        if(node->left == nullptr && node->right == nullptr){
            *maxsum = max(current, *maxsum);
        }
        
        dfs(node->left, current, maxsum);
        dfs(node->right, current, maxsum);
    }
    
};