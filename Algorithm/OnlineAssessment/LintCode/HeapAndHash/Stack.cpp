/*
495. Implement Stack
https://www.lintcode.com/problem/implement-stack/
Implement a stack. You can use any data structure inside a stack except stack itself to implement it.

Example 1:

Input:
push(1)
pop()
push(2)
top()  // return 2
pop()
isEmpty() // return true
push(3)
isEmpty() // return false
Example 2:

Input:
isEmpty()


*/

class Stack {

/*
Several ways to do it.
1. Use two queue to implement it
2. Use double linked list with a tail node to implement
*/


private:

    struct ListNode{
        int val;
        ListNode* prev;
        ListNode* next;
        
        ListNode(int n):val(n){
            prev = nullptr;
            next = nullptr;
        }
    };


private:
    ListNode* head;
    ListNode* tail;

    
public:

    // Constructor
    Stack(){
        head = new ListNode(0);
        tail = new ListNode(0);
        head->next = tail;
        tail->prev = head;
    }

    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        ListNode* xNode = new ListNode(x);
        
        ListNode* prevNode = tail -> prev;
        
        prevNode->next = xNode;
        xNode->next = tail;
        tail->prev = xNode;
        xNode->prev = prevNode;
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        if(isEmpty()){
            return;
        }
        
        ListNode* temp = tail->prev->prev;
        tail -> prev -> next = nullptr;
        temp -> next = tail;
        temp -> next -> prev = nullptr;
        tail -> prev = temp;
    }

    /*
     * @return: An integer
     */
    int top() {
        
        // write your code here
        if(isEmpty()){
           throw "Stack is Empty"; // ask interviewer how to deal with this
        }
        
        return tail->prev->val;
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        if(head->next == tail && tail->prev == head){
            return true;
        }
        
        return false;
    }
    
};