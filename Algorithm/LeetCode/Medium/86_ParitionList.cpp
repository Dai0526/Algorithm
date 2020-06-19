/*
https://leetcode.com/problems/partition-list/
就简单分两个list

一个全小于x, 一个大于等于x
最后拼接

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_hdr = new ListNode(-1);
        ListNode* less = less_hdr;
        
        ListNode* greater_hdr = new ListNode(-1);
        ListNode* greater = greater_hdr;
        
        while(head != nullptr){
            if(head->val < x){
                less->next = head;
                less = less->next;
            }else{
                greater->next = head;
                greater = greater->next;
            }
            
            head = head->next;
        }
        
        less->next = greater_hdr->next;
        greater->next = nullptr;
        return less_hdr->next;
    }
};