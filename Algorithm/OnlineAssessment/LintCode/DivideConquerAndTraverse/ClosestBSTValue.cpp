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
#include <math.h>
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
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        if (root == nullptr) {
            return 0;
        }
        
        TreeNode* lowerNode;
        TreeNode* upperNode;
        
        lowerNode = GetLowerBound(lowerNode, root, target);
        upperNode = GetUpperBound(upperNode, root, target);
        
        if(lowerNode == nullptr){
            return upperNode->val;
        }
        
        if(upperNode == nullptr){
            return lowerNode->val;
        }
        
        if (abs(target - lowerNode->val) > abs(target - upperNode->val)) {
            return upperNode->val;
        }
        
        return lowerNode->val;
    }
    
    //return node->val < target
    TreeNode* GetLowerBound(TreeNode* low, TreeNode* root, double target) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (target <= root->val) {
            return GetLowerBound(low, root->left, target);
        } 

        TreeNode* temp = GetLowerBound(low, root->right, target);
        
        if (temp == nullptr) {
            return root;
        }
        
        return temp;
    }
    
     TreeNode* GetUpperBound(TreeNode* up, TreeNode* root, double target) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (target > root->val) {
            return GetUpperBound(up, root->right, target);
        }
        
        TreeNode* temp = GetUpperBound(up, root->left, target);
        if (temp == nullptr) {
            return root;
        }
        return temp;
    }
};

/*
   TreeNode* GetLowerBound(TreeNode* root, double target) {
        if (root == nullptr) { return nullptr; }    
        if (target <= root->val) { return GetLowerBound(root->left, target); } 
        
        TreeNode* temp = GetLowerBound(root->right, target);
    
        if (temp == nullptr) { return root; }      
        return temp;
    }

    第一层 GetLowerBound(root, 6.1)
    运行到99行，TreeNode* temp = GetLowerBound(9, 6.1)，进入第二次递归
            第二层 GetLowerBound(9, 6.1)
            满足 if (target <= root->val) ，等在97行 return GetLowerBound(8, 6.1)的结果，进入第三次递归
                第三层 GetLowerBound(8, 6.1)
                满足 if (target <= root->val)，等在97行 return GetLowerBound(nullptr, 6.1)的结果 进入第四次递归
                    第四层递归GetLowerBound(nullptr, 6.1)
                    96行 if (root == nullptr)， 所以return Null 到第三层，退出第四层
                第三层97行的return得到了第四层的Null, 把这个Null 返回给第二层， 退出第三层
            第二层97行的return拿到Null之后，再return到第一层
    第一层99行的这个TreeNode* temp = nullptr了

*/