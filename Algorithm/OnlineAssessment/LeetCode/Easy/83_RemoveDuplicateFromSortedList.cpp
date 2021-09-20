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
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
               
        ListNode* node = head;
        while(node->next != nullptr){
            int v = node->val;
            
            if(v != node->next->val){
                node = node->next;
            }else{
                ListNode* temp = node->next;
                node->next = temp->next;
                delete temp;
            }
        }
        
        return head;
        
    }
};