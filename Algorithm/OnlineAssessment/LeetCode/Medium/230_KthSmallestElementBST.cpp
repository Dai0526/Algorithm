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
in order traversal for bst produces a sorted list

in order ： left, root, right

*/

#include <stack>

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        stack<TreeNode*> nodes;
        TreeNode* pDummy = root;
        
        while(pDummy != nullptr){
            nodes.push(pDummy);
            pDummy = pDummy->left;
        }
        
        vector<int> vec;
        
        while(!nodes.empty()){
            TreeNode* curr = nodes.top();
            vec.push_back(curr->val);
            
            if(vec.size() == k){
                return vec[k-1];
            }
            
            if(curr->right == nullptr){
                nodes.pop();
                while(!nodes.empty() && nodes.top()->right == curr){
                    curr = nodes.top();
                    nodes.pop();
                }
            }else{
                curr = curr->right;
                while(curr != nullptr){
                    nodes.push(curr);
                    curr = curr->left;
                }
            }
        }
        
        
        return -1;
    }
};