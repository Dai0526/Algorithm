/**
https://leetcode.com/problems/merge-two-sorted-lists/



 */
class Solution {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        
        if(l2 == nullptr){
            return l1;
        }
        
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                curr->next = l2;
                l2 = l2 -> next;
            }else{
                curr->next = l1;
                l1 = l1 -> next;
            }
            
            curr = curr->next;
        }
        
        while(l1 != nullptr){
            curr->next = l1;
            l1 = l1 -> next;
            curr = curr -> next;
        }
        
        
        while(l2 != nullptr){
            curr->next = l2;
            l2 = l2 -> next;
            curr = curr -> next;
        }
        
        return head->next;
    }

    ListNode* mergeTwoLists_rec(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr){
            return l2;
        }
        
        if(l2 == nullptr){
            return l1;
        }
        
        if(l1->val < l2->val){
            l1->next =  mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next =  mergeTwoLists(l1, l2->next);
            return l2;            
        }
    }
};