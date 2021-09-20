/*
https://leetcode.com/problems/insertion-sort-list/

dummy  1    2    4    5    6    3    
           pre  temp      curr
1. if find a node that curr->next->val < curr->val   (curr = 6, we will insert curr->next = 3)
    a. iterate a node pre from dummy
            i. find a node that pre->next->val >= curr->next->val   (pre = 2)
            ii.insert curr->next after pre
                    temp = pre->next;
                    pre->next = curr->next;
                    curr->next = curr->next->next;
                    pre->next->next = temp;
        
                    reset pre to front(dummy)
3. else curr->next->val < curr->val
    a. curr = curr->next;

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(-1);
        ListNode* pDummy = &dummy;
        
        pDummy->next = head;
        
        ListNode* pre = pDummy;
        ListNode* curr = head;
        
        while(curr != nullptr){
            
            // if next value < curr value, do a insertion
            if(curr->next != nullptr && curr->next->val < curr->val){
                // start from head, stop when pre->next > pre
                while(pre->next != nullptr && pre->next->val < curr->next->val){
                    pre = pre->next;
                }
                // insert curr->next node at pre->next
                ListNode* temp = pre->next;
                pre->next = curr->next;
                curr->next = curr->next->next;
                pre->next->next = temp;
                
                // reset preNode for next iteration
                pre = pDummy;
            }else{
                curr = curr->next;
            }
        }
        
        return pDummy->next;
    }
};