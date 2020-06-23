/**
https://leetcode.com/articles/swap-nodes-in-pairs/

注意Recursion的做法

每次直接对snd的下一个做recursive
然后swap 当前的，

每次返回新的第一个node, 因为是recursion，最后返回的就是新的head

        ListNode* fst = head;
        ListNode* snd = head->next;
        
        fst->next = swapPairs(snd->next);
        snd->next = fst;

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        
        
        ListNode* front = temp;
        ListNode* fst = head;
        while(fst != nullptr && fst->next != nullptr){
            //ListNode* fst = head;
            ListNode* snd = fst->next;
            
            front->next = snd;
            fst->next = snd->next;
            snd->next = fst;
            
            front = fst;
            fst = fst->next;  
        }
        
        return temp->next;
    }

    ListNode* recursion(ListNode* head) {
        if(head == nullptr || head->next  == nullptr){
            return head;
        }
        
        ListNode* fst = head;
        ListNode* snd = head->next;
        
        fst->next = swapPairs(snd->next);
        snd->next = fst;
        
        
        return snd;
    }

};