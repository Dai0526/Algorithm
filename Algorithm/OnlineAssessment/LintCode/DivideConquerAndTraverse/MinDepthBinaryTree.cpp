/*
155. Minimum Depth of Binary Tree
https://www.lintcode.com/problem/minimum-depth-of-binary-tree
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Example 1:
Input: {}
Output: 0

Example 2:
Input:  {1,#,2,3}
Output: 3	
Explanation:
	1
	 \ 
	  2
	 /
	3    
it will be serialized {1,#,2,3}
Example 3:

Input:  {1,2,3,#,#,4,5}
Output: 2	
Explanation: 
      1
     / \ 
    2   3
       / \
      4   5  
it will be serialized {1,2,3,#,#,4,5}

*/
#include <vector>
#include <algorithm>
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
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode * root) {
        if(root == nullptr){
            return 0;
        }
        
        int min = numeric_limits<int>::max();
        int current = 0;
        
        dfs(root, 0, &min);
        
        return min;
        
    }
    
    void dfs(TreeNode * root, int currentPath, int* minLevel){
        
        if(root == nullptr){
            return;
        }
        
        ++currentPath;
        
        if(root->left == nullptr && root->right == nullptr){
            *minLevel = min(currentPath, *minLevel);
        }
        
        dfs(root->left, currentPath, minLevel);
        dfs(root->right, currentPath, minLevel);
        currentPath -= 1;
    }
    
};