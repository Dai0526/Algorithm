/*
https://leetcode.com/problems/binary-tree-level-order-traversal/

level order traveral, typical BFS problem

 */

#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return vector<vector<int>>();
        }
        
        // init
        vector<vector<int>> out;
        queue<TreeNode*> q;
        q.push(root);
        
        //level order traversal, using bfs
        while(!q.empty()){
            //add all item in current level to result
            vector<int> currLevel;
            int qSize = q.size();
            
            for(int i = 0; i < qSize; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                currLevel.push_back(node->val);
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            
            out.push_back(currLevel);
            
        }
        
        return out;
    }
};