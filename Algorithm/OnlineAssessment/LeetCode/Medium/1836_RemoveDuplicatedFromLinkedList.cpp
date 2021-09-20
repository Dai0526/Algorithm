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
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> freq;
        
        ListNode dummy(-1);
        dummy.next = head;
        
        while(head != nullptr){
            ++freq[head->val];
            head = head->next;
        }
        
        ListNode *prev = &dummy;
        head = dummy.next;
        
        while(head != nullptr){
            int val = head->val;
            if(freq[val] > 1){
                prev->next = head->next;
                head->next = nullptr;
                head = prev->next;
            }else{
                head = head->next;
                prev = prev->next;
            }    
        }
        
        if(dummy.next == nullptr){
            return nullptr;
        }
        
        return dummy.next;
    }
};