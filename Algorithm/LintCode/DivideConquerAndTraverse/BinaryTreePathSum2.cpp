/**
246. Binary Tree Path Sum II
https://www.lintcode.com/problem/binary-tree-path-sum-ii/
Your are given a binary tree in which each node contains a value. Design an algorithm to get all paths which sum to a given value. The path does not need to start or end at the root or a leaf, but it must go in a straight line down.

Example
Example 1:

Input:
{1,2,3,4,#,2}
6
Output:
[[2, 4],[1, 3, 2]]
Explanation:
The binary tree is like this:
    1
   / \
  2   3
 /   /
4   2
for target 6, it is obvious 2 + 4 = 6 and 1 + 3 + 2 = 6.
Example 2:

Input:
{1,2,3,4}
10
Output:
[]
Explanation:
The binary tree is like this:
    1
   / \
  2   3
 /   
4   
for target 10, there is no way to reach it.
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
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // get all path, find valid 
        vector<vector<int>> paths;
        if(root == nullptr){
            return paths;
        }

        //get all path
        vector<int> p;
        dfs(root, target, p, paths);
        
        return paths;
    }
    
    // modified, for each next node, calculate
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& result){
        if(root == nullptr){
            return;
        }
        
        path.push_back(root->val);
        
        
        int sum = 0;
        //递归由上到下，所以从反开始 --???!!!不懂
        for (int i = path.size() - 1; i >=0; --i) {
            sum += path[i];
            
            if (sum == target) {

                vector<int> temp;
                for(int j = i; j < path.size(); ++j){
                    temp.push_back(path[j]);
                }
                result.push_back(temp);
            }
        }
        
        
        dfs(root->left, target, path, result);
        dfs(root->right, target, path, result);
        path.pop_back();

    }
    
};