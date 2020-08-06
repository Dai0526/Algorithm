/*
https://leetcode.com/problems/reorder-list/
find middle node

0  1  2  3  4  5  6

1. Find 3 part
head  0
fst   1  2  3  
snd   4  5  6

        // find mid node
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

2. reverse snd  6  5  4
        // reverse the snd half
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        ListNode* curr = slow;
        
        while(curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
3. cross connect fst and snd 6 1 5 2 4 3
        // merge part1 and part2
        ListNode* fst = head;
        ListNode* snd = prev;
        // reuse temp node
        while(snd->next != nullptr){
            temp = fst->next;
            fst->next = snd;
            fst = temp;
            
            temp = snd->next;
            snd->next = fst;
            snd = temp;
        }
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
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return;
        }
               
        // find mid node
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the snd half
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        ListNode* curr = slow;
        
        while(curr != nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // merge part1 and part2
        ListNode* fst = head;
        ListNode* snd = prev;
        // reuse temp node
        while(snd->next != nullptr){
            temp = fst->next;
            fst->next = snd;
            fst = temp;
            
            temp = snd->next;
            snd->next = fst;
            snd = temp;
        }
        
    }
};