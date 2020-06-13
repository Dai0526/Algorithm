/**
70. Binary Tree Level Order Traversal II
https://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

Example 1:

Input: {1,2,3}
Output: [[2,3],[1]]
Explanation:
    1
   / \
  2   3
it will be serialized {1,2,3}

Example 2:
Input: {3,9,20,#,#,15,7}
Output: [[15,7],[9,20],[3]]
Explanation:
    3
   / \
  9  20
    /  \
   15   7
it will be serialized {3,9,20,#,#,15,7}
 */

#include <queue>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {    
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
    
public:
    /**
     * @param root: A tree
     * @return: buttom-up level order a list of lists of integer
     */
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        
        if(root == nullptr){
            return vector<vector<int>>();
        }
        
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        stack<vector<int>> resContainer;
        
        while(!myQueue.empty()){
            
            int qSize = myQueue.size();
            vector<int> thisLevel(qSize);

            for(int i = 0; i < qSize; ++i){
                TreeNode* curr = myQueue.front();
                myQueue.pop();

                thisLevel[i] = curr->val;
                
                if(curr->left != nullptr){
                    myQueue.push(curr->left);
                }
                
                if(curr->right != nullptr){
                    myQueue.push(curr->right);
                }
                
            }
            
            resContainer.push(thisLevel);
        }
        
        
        vector<vector<int>> output;
        int stackSize = resContainer.size(); //****注意这个size！！！
        for(int i=0; i<stackSize; ++i){
            vector<int> level = resContainer.top();
            output.push_back(level);
            resContainer.pop();
        }
        
        return output;
    }
};