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
https://leetcode.com/problems/add-two-numbers/
Since it is reverse order, thus do Basic math arithmetic
Use a carrier to save moving 1

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans = new ListNode(-1);
        ListNode* curr = ans;
        ListNode* fst = l1;
        ListNode* snd = l2;
        
        int carrier = 0;
        
        while(fst != nullptr && snd != nullptr){
            int n1 = fst->val;
            int n2 = snd->val;
            
            int sum = carrier + n1 + n2;
            carrier = sum / 10;
            int val = sum % 10;
            
            curr->next = new ListNode(val);
            
            fst = fst->next;
            snd = snd->next;
            curr = curr->next;
        }
        
        
        // deal with leftover
        while(fst != nullptr){
            int sum = carrier + fst->val;
            carrier = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            fst = fst->next;
            curr = curr->next;
        }
        
        while(snd != nullptr){
            int sum = carrier + snd->val;
            carrier = sum / 10;
            curr->next = new ListNode(sum % 10);
            
            snd = snd->next;
            curr = curr->next;
        }
        
        if(carrier > 0){
            curr->next = new ListNode(carrier);
        }
        
        return ans->next;
    }
};