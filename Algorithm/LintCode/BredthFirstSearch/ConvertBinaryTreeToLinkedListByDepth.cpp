/*
242. Convert Binary Tree to Linked Lists by Depth
https://www.lintcode.com/problem/convert-binary-tree-to-linked-lists-by-depth/
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Example 1:
Input: {1,2,3,4}
Output: [1->null,2->3->null,4->null]
Explanation: 
        1
       / \
      2   3
     /
    4

Example 2:
Input: {1,#,2,3}
Output: [1->null,2->null,3->null]
Explanation: 
    1
     \
      2
     /
    3
*/

#include <vector>
#include <queue>

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

    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        vector<ListNode*> out;
        if(root == nullptr){
            return out;
        }

        queue<TreeNode*> myQueue;  
        myQueue.push(root);
        
        while(!myQueue.empty()){
            
            int qSize = myQueue.size();
            ListNode* dummy = new ListNode(0);
            ListNode* head = dummy;
            for(int i = 0; i < qSize; ++i){
                TreeNode* tNode = myQueue.front();
                myQueue.pop();
            
                ListNode* lRoot = new ListNode(tNode->val);
                dummy->next = lRoot;
                dummy = dummy -> next;
                
                if(tNode->left != nullptr){
                    myQueue.push(tNode->left);
                }
        
                if(tNode->right != nullptr){
                    myQueue.push(tNode->right);
                }
            } 
            out.push_back(head->next);
        }      
        return out;      
    }
};