/*
https://leetcode.com/problems/rotate-list/
IDEA
 k can be larger than size of list
 
 k mod size to get true rotation places
 two pointers a and b, k intervel
    when b -> next is null
     1 2 3 4 5 6 null   k = 2
           |   |
           a   b
     b->next = head
     res = a -> next
     a->next = nullptr
         
     return res
*/

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

    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

   
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        int size = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            ++size;
            temp = temp->next;
        }
        
        int nRotate = k % size;
        
        if(nRotate == 0){
            return head;
        }
        
        ListNode* front = head;
        ListNode* after = head;
        
        for(int i = 0; i < nRotate; ++i){
            after = after->next;
        }
        
        while(after->next != nullptr){
            after = after->next;
            front = front->next;
        }
        
        after->next = head;
        ListNode* newHead = front->next;
        front->next = nullptr;
        
        return newHead;
        
    }
};