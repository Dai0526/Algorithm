/*
71. Binary Tree Zigzag Level Order Traversal
https://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal/
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

Example 1:
Input:{1,2,3} Output:[[1],[3,2]]
Explanation:
    1
   / \
  2   3
it will be serialized {1,2,3}

Example 2:
Input:{3,9,20,#,#,15,7} Output:[[3],[20,9],[15,7]]
Explanation:
    3
   / \
  9  20
    /  \
   15   7
it will be serialized {3,9,20,#,#,15,7}

 */

#include <vector>
#include <queue>
#include <algorithm>
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
     * @param root: A Tree
     * @return: A list of lists of integer include the zigzag level order traversal of its nodes' values.
     */
     
    enum Order{
        ZIG = 0,
        ZAG = 1
    }; 
     
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        if(root == nullptr){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> out;
        queue<TreeNode*> candidates;
        candidates.push(root);
        
        Order zzOrder = Order::ZIG;
        
        while(!candidates.empty()){
            
            int qSize = candidates.size();
            vector<int> thisLevel;
            
            for(int i = 0; i < qSize; ++i){
                TreeNode* curr = candidates.front();
                candidates.pop();
                thisLevel.push_back(curr->val);
                
                if(curr->left != nullptr){
                    candidates.push(curr->left);
                }
                
                if(curr->right != nullptr){
                    candidates.push(curr->right);
                }
            }
            
            zzOrder = AddLevel(zzOrder, thisLevel);    
            out.push_back(thisLevel);       
        }
        
        return out;
        
    }
    
    Order AddLevel(Order odr, vector<int>& level){
        switch(odr){
            case Order::ZAG:
                reverse(level.begin(), level.end());
                odr = Order::ZIG;
                break;
            case Order::ZIG:
            default:
                odr = Order::ZAG;
                break;
        }
        
        return odr;
    }
    
};