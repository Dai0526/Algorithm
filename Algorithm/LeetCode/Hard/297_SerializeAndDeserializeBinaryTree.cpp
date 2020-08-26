/**
https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 */
#include <sstream>
#include <queue>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Codec {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //bfs
        if(root == nullptr){
            return "";
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        stringstream ss;
        
        while(!q.empty()){
            int qsize = q.size();
            
            for(int i = 0; i < qsize; ++i){
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr == nullptr){
                    ss << "*,";
                    continue;
                }
                
                //else
                ss << curr->val << ",";
                
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        cout << ss.str();
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        
        vector<string> vec;
        split(data, vec, ',');
        
        TreeNode* root = getTreeNode(vec[0]);
        
        queue<TreeNode*> q;
        q.push(root);
        int idx = 1;
        
        
        
        
        while(!q.empty() && idx < vec.size()){
            TreeNode* curr = q.front();
            q.pop();
            
            if(idx < vec.size()){
                curr->left = getTreeNode(vec[idx]);
                ++idx;
                
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
            }
            
            if(idx < vec.size()){
                curr->right = getTreeNode(vec[idx]);
                ++idx;
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
        }
    
        return root;
        
    }
    
    void split(string& s, vector<string>& tks, char delimeter){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delimeter))
        {
            tks.push_back(token);
        }   
    }
    
            
    TreeNode* getTreeNode(string str){
        if(str == "*"){
            return nullptr;
        }
        TreeNode* temp = new TreeNode(stoi(str));
        return temp;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));