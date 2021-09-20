
/*

https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

1. Use idea of Level Order traversal
2. a variable to record sequence

BFS use a queue to record each level

*/

#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return vector<vector<int>>();
        }
        
        vector<vector<int>> zigzag;
        queue<TreeNode*> myQueue;
        
        myQueue.push(root);
        bool zig = true;
        
        while(!myQueue.empty()){
            
            int qSize = myQueue.size();
            vector<int> thisLvl;
            for(int i = 0; i < qSize; ++i){
                TreeNode* node = myQueue.front();
                myQueue.pop();
                
                thisLvl.push_back(node->val);
                
                if(node->left != nullptr){
                    myQueue.push(node->left);                    
                }
                
                if(node->right != nullptr){
                    myQueue.push(node->right);                    
                }                
            }
            
            if(!zig){
                reverse(thisLvl.begin(), thisLvl.end());  
            }
            
            zig = !zig;
            zigzag.push_back(thisLvl);
            
        }
        
        return zigzag;
        
    }
};