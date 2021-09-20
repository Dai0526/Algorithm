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
class Solution {
public:
    
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        // Get height - keep go left to find height
        int height = 0;
        TreeNode* pTemp = root;
        while(pTemp->left != nullptr){
            ++height;
            pTemp = pTemp->left;
        }

        int n =  (int)pow(2, height) - 1;
        
        // binary search each depth
        int left = 1;
        int right = n;
        int mid;
        
        pTemp = root;
        
        while(left <= right){
            mid = left + (right - left) / 2;
            
            if(find(mid, height, n, pTemp)){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
            
        }
        
        return n + left;
    }
    
    bool find(int idx, const int depth, const int nNodes, TreeNode* node){
        int left = 0; 
        int right = nNodes;
        int mid;
        
        for(int i = 0; i < depth; ++i){
            mid = left + (right - left) / 2;
            
            if(idx <= mid){
                node = node->left;
                right = mid;
            }else{
                node = node->right;
                left = mid + 1;
            }
        }
        
        return node != nullptr;
    }
    
    
    int countNodes_rec(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};