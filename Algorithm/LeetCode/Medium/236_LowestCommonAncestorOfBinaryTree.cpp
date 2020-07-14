/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Recursion

Check for each subtree
Result shall contain
    1. parent node
    2. contain p
    3. contain q.
    
基本LCA思路
    # A,B 都在 root 为根的二叉树里, return lca(A,B)
    # 如果 A,B 都不在 root 为根的二叉树里, return None
    # 如果只有 A 在，return A
    # 如果只有 B 在，return B
对于本题
Furthermore, we can add more details to the return value to amke it more generic

    # A,B 都在 root 为根的二叉树里, return lca(A,B)
    # 如果 A,B 都不在 root 为根的二叉树里, return None
    # 如果只有 A 在，return has A, no B, A node
    # 如果只有 B 在，return no A, has B, B node
    # 最后做一个判断，如果AB有一个不在，就return None    
    
*/

class Solution {
    
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


struct Result{
    bool hasp;
    bool hasq;
    TreeNode* pNode;
    
    Result(TreeNode* n, bool p, bool q){
        pNode = n;
        hasp = p;
        hasq = q;
    }
};
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return nullptr;
        }
        
        Result res = LCA(root, p, q);
        
        if(res.hasp && res.hasq){
            return res.pNode;
        }
        
        return nullptr;
    }
    
    Result LCA(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr){
            return Result(nullptr, false, false);
        }
        
        Result left = LCA(node->left, p, q);
        Result right = LCA(node->right, p, q);
        
        bool existp = left.hasp || right.hasp || node == p;
        bool existq = left.hasq || right.hasq || node == q;
        
        // if p or q is current node
        if(p == node || q == node){
            return Result(node, existp, existq);
        }
        
        // if root is not p/q, and left,right has a node that pq exist
        if(left.pNode != nullptr && right.pNode != nullptr){
            return Result(node, existp, existq);
        }
        
        // if left subtree is not null
        if(left.pNode != nullptr){
            return Result(left.pNode, existp, existq);
        }
        
        if(right.pNode != nullptr){
            return Result(right.pNode, existp, existq);
        }
        
        
        return Result(nullptr, existp, existq);
    }
    
};