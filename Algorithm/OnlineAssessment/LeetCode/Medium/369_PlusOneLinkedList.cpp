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
https://leetcode.com/problems/plus-one-linked-list/
Use Stack and carry
*/
#include <stack>
using namespace std;

class Solution {

public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* plusOne(ListNode* head) {
        
        if(head == nullptr){
            return head;
        }
        
        
        stack<ListNode*> digits;
        ListNode* temp = head;
        
        while(temp != nullptr){
            digits.push(temp);
            temp = temp->next;
        }
        
        int carry = 1;
        
        while(!digits.empty()){
            ListNode* curr = digits.top();
            
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;
            
            digits.pop();
        }
        
        if(carry > 0){
            ListNode* leading = new ListNode(carry, head);
            return leading;
        }
        
        return head;
        
    }
};