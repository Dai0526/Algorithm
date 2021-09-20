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
BST inorder is a sorted list, find two unsorted value, then swap value
https://leetcode.com/problems/recover-binary-search-tree/

*/

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        int num1 = -1, num2 = -1;
        
        inorder(root, nodes);
        findTwoNodes(nodes);   
    }
    
    void inorder(TreeNode* root, vector<TreeNode*>& nodes){
        if(root == nullptr){
            return;
        }
        
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }
    
    void findTwoNodes(vector<TreeNode*>& nodes){
        // find two node
        int n = nodes.size();
        int idx1 = -1; 
        int idx2 = -1;
        
        for(int i = 0; i < n - 1; ++i){
            TreeNode* node1 = nodes[i];
            TreeNode* node2 = nodes[i + 1];
             
            if(node1->val < node2->val){
                continue;
            }
            
            idx2 = i + 1;
            if(idx1 == -1){
                idx1 = i;
            }else{
                //cout << "idx = " << idx1 << ", idx2 = " << idx2 << endl;
                break; // find both occurance, break;
            } 
        }
        
        //swap
        int temp = nodes[idx1]->val;
        nodes[idx1]->val = nodes[idx2]->val;
        nodes[idx2]->val = temp; 
    }

};