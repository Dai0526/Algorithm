/*
902. Kth Smallest Element in a BST
https://www.lintcode.com/problem/kth-smallest-element-in-a-bst
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example 1:
Input：{1,#,2},2
Output：2
Explanation：
	1
	 \
	  2
The second smallest element is 2.

Example 2:
Input：{2,1,3},1
Output：1
Explanation：
  2
 / \
1   3
The first smallest element is 1.
Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Notice
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

对于bst, in order traversal 就是一个sorted list
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
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    
    struct Result{
        
        int value;
        int Nth;
    };
    
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        
        // create a vector which is sorted node, then just index it to find value
        TreeNode* temp = root;
        Result res;
        res.Nth = k;
        InorderK(temp, res);
        
        return res.value;
        
    }
    
        
    // 2. improved one time query version, which only did k times
    void InorderK(TreeNode* root, Result& r){
        if(r.Nth == 0 || root == nullptr){
            return;
        }
        
        InorderK(root->left, r);
        if(r.Nth  > 0){
            r.value = root -> val;
            r.Nth --;
        }
        
        InorderK(root->right, r);
        
    }
    
public:    
    // recursion verison
    // 1. find all and save in al ist, then you can find any kth smallest
    //    The good part for it is that later on the fecth is only O(1)
    // 
    
    int kthSmallestInorder(TreeNode * root, int k) {
        // write your code here
        
        // create a vector which is sorted node, then just index it to find value
        
        if(k == 0 || root == nullptr){
            return numeric_limits<int>::min();
        }
        
        TreeNode* temp = root;
        vector<int> sorted;
        Inorder(temp, sorted);
        
        return sorted[k - 1];
        
    }
    
    void Inorder(TreeNode* root, vector<int>& vec){
        if(root == nullptr){
            return;
        }
        
        Inorder(root->left, vec);
        vec.push_back(root->val);
        Inorder(root->right, vec);
        
    }

};