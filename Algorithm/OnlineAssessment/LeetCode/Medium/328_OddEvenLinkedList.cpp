/*
https://leetcode.com/problems/odd-even-linked-list/
Iterate list, keep a odd list and even list, then concat together

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        
        // init even node number list
        ListNode even(-1);
        ListNode* pEven = &even;
        ListNode* pEvenHeader = &even;
        
        ListNode prev(-1);
        ListNode* pPrev = &prev;
        pPrev->next = head;
        
        ListNode* pNode = head;   // working node
        ListNode* newHdr = pPrev; // record for list header
        
        int count = 1;
        while(pNode != nullptr){
            if(count % 2 == 0){
                // even node number
                pEven->next = pNode;        // append to even list
                pPrev->next = pNode->next;  // remove node from odd list
                pNode->next = nullptr;  // finish append even list
                pNode = pPrev->next;    // reset odd node ptr
                pEven = pEven->next;    // reset even node ptr
            }else{
                pNode = pNode->next;
                pPrev = pPrev->next;
            }
            ++count; // increment node number
        }
             
        // concat
        if(pEvenHeader->next != nullptr){
            pPrev->next = pEvenHeader->next;
        }
        
        return newHdr->next;    
    }
};