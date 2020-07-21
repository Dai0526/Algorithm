/*
https://leetcode.com/problems/linked-list-cycle/submissions/

Base idea is two pointers, fast and slow to see if met.
Two ways to write it.

*/


class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

public:
    bool hasCycle1(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                return true;
            }
        }
        
        return false;
    }
    
    // 不同写法
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != slow){
            
            if(fast == nullptr || fast->next == nullptr){
                return false;
            }
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
    
};