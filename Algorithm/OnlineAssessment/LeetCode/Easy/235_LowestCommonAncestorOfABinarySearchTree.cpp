/*
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Recursion

Need to know if current node's subtree has p/q or not.
Complicated return value, thus use a struct to work around it.

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
    bool hasA;
    bool hasB;
    TreeNode* pRoot; // ancestor candidate
    
    Result(TreeNode* node, bool a, bool b){
        hasA = a;
        hasB = b;
        pRoot = node;
    }
};   
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result res = LCA(root, p, q);
        
        if(res.hasA && res.hasB){
            return res.pRoot;
        }
        
        return nullptr;
    }
    
    Result LCA(TreeNode* root, TreeNode* A, TreeNode* B){
        if(root == nullptr){
            return Result(nullptr, false, false);
        }
        
        // keep go to left and right subtree
        Result left = LCA(root->left, A, B);
        Result right = LCA(root->right, A, B);
        
        // get cureent AB exist result
        bool existA = left.hasA || right.hasA || root == A;
        bool existB = left.hasB || right.hasB || root == B;
        
        // pass up A,B existed info
        if(root == A || root == B){
            return Result(root, existA, existB);
        }
        
        // cases 2 
        if(left.pRoot != nullptr && right.pRoot != nullptr){
            return Result(root, existA, existB);
        }
        
        // one of the subtree is nullptr
        if(left.pRoot != nullptr){
            return Result(left.pRoot, existA, existB);
        }
        
        if(right.pRoot != nullptr){
            return Result(right.pRoot, existA, existB);
        }
        
        return Result(nullptr, existA, existB);
    }

    /*
    题目要求是BST, 所以解法更简单
    从root往下，只要发现一个node 比一个大，比另一个小，就return他
    
    */
    TreeNode* LCA_BST(TreeNode* root, TreeNode* p, TreeNode* q){
        int parent = root->val;
        
        int pv = p->val;
        int qv = q->val;
        
        if(pv > parent && qv > parent){
            return LCA_BST(root->right, p, q);
        }
        
        if(pv < parent && qv < parent){
            return LCA_BST(root->left, p, q);
        }
        
        // found
        return root;
  
    }

};