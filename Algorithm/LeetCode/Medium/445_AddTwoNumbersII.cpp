/*
Prefer to add from right to left,
Since it is a single linkedlist, use two stack to reverse orders

then do arithmic for each digits

Corner Case:
1. l1 and l2 size not match
2. the leading digits? need to check if carry == 1?
    [5], [5] = 10


*/

#include <stack>
#include <vector>

using namespace std;

class Solution {


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        
        stack<int> stk1;
        stack<int> stk2;
        
        while(l1 != nullptr){
            stk1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2 != nullptr){
            stk2.push(l2->val);
            l2 = l2->next;
        }   
        
        ListNode dummy(-1);
        ListNode* pDummy = &dummy;
        
        int add = 0;
        
        while(!stk1.empty() && !stk2.empty()){
            
            int digit = stk1.top() + stk2.top() + add;
            stk1.pop();
            stk2.pop();
                
            if(digit >= 10){
                digit -= 10;
                add = 1;
            }else{
                add = 0;
            }
            
            ListNode* temp = new ListNode(digit);
            temp->next = pDummy->next;
            pDummy->next = temp;
        }
        
        
        // finish left over
        
        while(!stk1.empty()){
            int digit = stk1.top() + add;
            stk1.pop();
            
            if(digit >= 10){
                digit -= 10;
                add = 1;
            }else{
                add = 0;
            }
            
            ListNode* temp = new ListNode(digit);
            temp->next = pDummy->next;
            pDummy->next = temp;
        }
        
        while(!stk2.empty()){
            int digit = stk2.top() + add;
            stk2.pop();
            
            if(digit >= 10){
                digit -= 10;
                add = 1;
            }else{
                add = 0;
            }
            
            ListNode* temp = new ListNode(digit);
            temp->next = pDummy->next;
            pDummy->next = temp;
        }
        
        // check last digit
        if(add == 1){
            ListNode* temp = new ListNode(1);
            temp->next = pDummy->next;
            pDummy->next = temp;
        }
        
        return pDummy->next;
    }
};