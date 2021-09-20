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
BFS

*/

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
         if(root == nullptr){
             return res;
         }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int qsize = q.size();
            vector<int> level;
            
            for(int i = 0; i < qsize; ++i){
                
                TreeNode* temp = q.front();
                q.pop();
                
                level.push_back(temp->val);
                
                if(temp->left != nullptr){
                    q.push(temp->left);
                }
                
                if(temp->right != nullptr){
                    q.push(temp->right);
                }
                
            }
            
            res.push_back(level);     
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};