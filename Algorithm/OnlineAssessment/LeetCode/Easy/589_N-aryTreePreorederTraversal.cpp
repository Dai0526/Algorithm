/*
https://leetcode.com/problems/n-ary-tree-preorder-traversal/submissions/858470500/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(root == nullptr){
            return vector<int>();
        }

        vector<int> ans;
        stack<Node*> myStack;

        myStack.push(root);

        while(myStack.size() > 0){
            
            Node* curr = myStack.top();
            myStack.pop();
            ans.push_back(curr->val);

            if(curr->children.size() == 0){
                continue;
            }

            reverse(curr->children.begin(), curr->children.end());

            for(Node* pNode : curr->children){
                myStack.push(pNode);
            }

        }

        return ans;

    }
};