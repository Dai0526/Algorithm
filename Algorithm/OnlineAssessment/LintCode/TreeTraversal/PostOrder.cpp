/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
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
     * @param root: A Tree
     * @return: Postorder in ArrayList which contains node values.
     */
    vector<int> postorderTraversal(TreeNode * root) {
        vector<int> result;
        
        postOrderRecursive(root, result);
        
        return result;
    }
    
    void postOrderRecursive(TreeNode* node, vector<int>& output){
        
        if(node == nullptr){
            return;
        }
        
        postOrderRecursive(node->left, output);
        postOrderRecursive(node->right, output);
        output.push_back(node->val);
    }
    

};