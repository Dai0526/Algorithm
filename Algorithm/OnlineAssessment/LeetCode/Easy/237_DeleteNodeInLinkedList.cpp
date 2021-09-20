/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        
        int value = next->val;
        next->val = node->val;
        node->val = value;
        
        node->next = next->next;
        next->next = nullptr;
        delete next;   
    }
};