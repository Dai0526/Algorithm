/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

注意要把重复出现过的node全部去除掉
1. 反过来用添加的思想
2. 从head开始，发现和下一个重复，把flag设为true, 不停移动到不同的那一个
3. 然后，如果flag true， 添加curr到dummy的后面

最后把curr->next设为nullpter作为结尾

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
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        bool duplicated = false;
        
        while(head != nullptr){
            while(head != nullptr && head->next != nullptr && head->val == head->next->val){
                duplicated = true;
                head = head -> next;
            }
            
            if(!duplicated){
                curr -> next = head;
                curr = curr -> next;
            }
            
            head = head->next;
            duplicated = false;
        }
        
        curr->next = nullptr;
        
        return dummy->next;
        
    }
};