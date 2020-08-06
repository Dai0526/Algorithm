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
MergeSort or QuickSort

Here we use merge sort

*/

class Solution {
public:
ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *slow{head}, *fast{head->next};
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return mergeList(sortList(head),sortList(fast));
    }
    
    ListNode* mergeList(ListNode* p1, ListNode* p2){
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        while(p1 && p2){
            if(p1->val < p2->val){
                current->next = p1;
                p1 = p1->next;
            }else{
                current->next = p2;
                p2 = p2->next;
            }
            current = current->next;
        }
        if(p1){
            current->next = p1;
        }else{
            current->next = p2;
        }
        current = dummy->next;
        delete dummy;
        return current;
    }
    
};