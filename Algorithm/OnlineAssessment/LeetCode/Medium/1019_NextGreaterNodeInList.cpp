/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*

1. use a stack to record the index of previous unfound value
2. use vector to save ans

iterate list

If stack not empty(there is value unfound） && that value is less then current:
    means it is the next larger value of it, then update ans with this value at idx

push current ans size as the index to the stack.
push list node value to vector

*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> stk;
        while(head != nullptr){
            
            while(!stk.empty() && ans[stk.top()] < head->val){
                ans[stk.top()] = head->val;
                stk.pop();
            }
            
            stk.push(ans.size());
            ans.push_back(head->val);
            head = head->next;
        }
        
        int n = stk.size();
        for(int i = 0; i < n; ++i){
            ans[stk.top()] = 0;
            stk.pop();
        }
        
        return ans;
        
    }
};