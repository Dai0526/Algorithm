/*

108. Convert Sorted Array to Binary Search Tree
Pre Order traversal

[.....] mid [...]
find mid as current root, recursivly do this step 

*/

#include <vector>

using namespace std;

class Solution {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(0, nums.size() - 1, nums);
    }
    
private:
    TreeNode* traversal(int left, int right, const vector<int>& nums){
        if(left > right){
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        
        // node left right
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traversal(left, mid - 1, nums);
        root->right = traversal(mid + 1, right, nums);
        
        return root;
    }
  
};