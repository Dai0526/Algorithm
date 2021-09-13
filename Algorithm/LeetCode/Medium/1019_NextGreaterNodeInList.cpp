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