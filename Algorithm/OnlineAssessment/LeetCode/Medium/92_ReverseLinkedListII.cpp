
/*

1  ->   2  ->   3  ->   4     5     6
prev  temp  
      curr   
1. find the node right before m, set a ptr prev to it.
2. start to iterating, and reverse 
    a. put prev->next = curr->next
     1  ->  3
     2  ->  3   ->   4     5     6
    b. set curr->next = curr->next->next
     1  ->  3
     2  ->   4     5     6
    c. prev ->next -> next = temp

下一个loop更好理解
1  ->   3  ->   2  ->   4     5     6
prev   temp    curr
    a. put prev->next = curr->next
        1  ->  4  ->   5     6
        prev      
        3  ->  2  ->  4     5     6
        temp  curr   

    b. set curr->next = curr->next->next
        1  ->  4  ->   5     6
        prev      
        3  ->  2  ->  5     6
        temp  curr
    c. prev ->next -> next = temp
        1  ->  4  ->  3  ->  2  ->  5->6    
       prev                 curr

once prev and curr is set, they don't change
but the connection is keeping changing(revese with the next)
      
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr){
            return head;
        }
        
        ListNode dummy(-1); 
        ListNode* prev = &dummy;
        dummy.next = head;
        
        for(int i = 0; i < m - 1; ++i){
            prev = prev->next;
        }
        
        ListNode* curr = prev->next;
        
        for(int i = 0; i < n - m; ++i){
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }
        
        return dummy.next;
    }
};