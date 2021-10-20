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
https://leetcode.com/problems/construct-binary-tree-from-string/
use stack

1. if is number, make node and push to stack
2. if is right bracket
    pop twice t1, t2
    if t2 has left, then t1 is the right child of t2
    else t1 is the left of t2
    
    push t2 back



*/

class Solution {
public:
    TreeNode* str2tree(string s) {
        int len = s.length();
        if(len == 0){
            return nullptr;
        }
        
        stack<TreeNode*> tnStack;
                
        for(int i = 0; i < len; ++i){
            if(s[i] == '-' || isdigit(s[i])){
                int l = i + 1;
                while(l < len && isdigit(s[l])){
                    ++l;
                }

                string val = s.substr(i, l - i);

                TreeNode* curr = new TreeNode(stoi(val));
                tnStack.push(curr);
                i = l - 1;
                
            }else if(s[i] == ')'){
                TreeNode* child = tnStack.top();
                tnStack.pop();
                
                TreeNode* parent = tnStack.top();
                
                if(parent->left != nullptr){
                    parent->right = child;
                }else{
                    parent->left = child;
                }

            }
        }
        
        return tnStack.top();
    }
};