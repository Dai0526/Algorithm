/*
https://leetcode.com/problems/palindrome-linked-list/submissions/

Time O(n)
Space O(1) - work on original list

reverse the second half, and then compare one by one.

Note that the best practice is to reverse it back before return.

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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        
        //find half and second half
        ListNode* fstTail = getHalfNode(head); // tail of first half
        ListNode* sndHead = reverse(fstTail->next);
        
        // check palindrome by two pointer
        ListNode* fst = head;
        ListNode* snd = sndHead;
        
        bool isPali = true;
        while(snd != nullptr){
            if(fst->val != snd->val){
                isPali = false;
                break;
            }
            
            fst = fst->next;
            snd = snd->next;
        }
        
        // restore orignal list by reverse second half back
        reverse(sndHead);
        
        return isPali;
        
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    
    ListNode* getHalfNode(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return slow;
    }
};