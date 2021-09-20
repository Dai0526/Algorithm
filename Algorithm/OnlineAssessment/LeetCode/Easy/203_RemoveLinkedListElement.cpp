/**
 * https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return nullptr;
        }
        
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        
        ListNode* temp = prev;//new head
        
        while(prev->next != nullptr){
            if(prev->next->val == val){
                ListNode* next = prev->next;
                prev->next = next->next;
                delete next;
            }else{
                prev = prev->next;
            }
        }
        
        return temp->next;
    }
};