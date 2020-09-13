/**
 https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Problem said that n is always valid, thus, after moving back ptr
n nodes, if it is nullptr, it means the first node should be removed.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return nullptr;
        }
        
        ListNode* front = head;
        ListNode* back = head;
        
        // move back n steps
        for(int i = 0; i < n; ++i){
            back = back->next;
        }
        
        if(back == nullptr){
            return head->next;
        }
        
        // find nth node
        while(back->next != nullptr){
            back = back->next;
            front = front->next;
        }
        
        ListNode* temp = front->next;
        front->next = temp->next;
        delete temp;
        
        return head;
    }
};