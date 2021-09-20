/*
https://leetcode.com/problems/linked-list-cycle-ii/
1. Space O(n)
Use a hashmap, or set,
keep adding it, once found duplicated, then return this node

2. Space O(1)
a. slow & fast to find the intersection
b. then from head to intersection, keep moving next to find cycle node.

*/


#include <unordered_set>

using namespace std;

class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

public:
    
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                hasCycle = true;
                break;
            }  
        }
        
        if(!hasCycle){
            return nullptr;
        }
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = slow;
        
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        
        return ptr1;
    }
    
    ListNode *detectCycle_Space(ListNode *head) {
        unordered_set<ListNode*> rec;
        
        ListNode* curr = head;
        
        while(curr != nullptr){
            if(rec.find(curr) != rec.end()){
                return curr;
            }
            
            rec.insert(curr);
            curr = curr->next;
            
        }
        
        return nullptr;
    }
};