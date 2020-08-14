/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**SA
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
BST inorder is a sorted list, the mid is the root of a bst
Thus, we can use it to reconstruct a binary tree

*/
#include <vector>
using namespace std;

class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        
        vector<int> nums;
        ListNode* temp = head;
        while(temp != nullptr){
            nums.push_back(temp->val);
            temp = temp->next;
        }
    
        return reconstruct(nums, 0, nums.size() - 1);
        
    }
    
    TreeNode* reconstruct(vector<int>& vec, int l, int r){
        if(l > r){
            return nullptr;
        }
        
        int mid = l + (r - l) / 2;
        
        //Inorder : left, root, right
        TreeNode* leftNode = reconstruct(vec, l, mid - 1);
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = leftNode;
        
        root->right = reconstruct(vec, mid + 1, r);
        
        return root;   
    }
};