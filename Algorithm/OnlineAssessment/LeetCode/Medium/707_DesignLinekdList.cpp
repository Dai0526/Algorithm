/*
Single linkedlist

https://leetcode.com/problems/design-linked-list/
*/

class MyLinkedList {

struct ListNode{
    int val;
    ListNode* next;
    
    ListNode(int v){
        val = v;
        next = nullptr;
    }
    
};  
    
private:
    
    ListNode* head;
    int size;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new ListNode(-1);
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size){
            return -1;
        }
        
        ListNode* temp = head->next;
        while(index > 0){
            temp = temp->next;
            --index;
        }
        
        return temp->val; 
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* tar = new ListNode(val);
        ListNode* temp = head->next;
        tar->next = temp;
        head->next = tar;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        ListNode* tar = new ListNode(val);
        temp->next = tar;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }
        
        ListNode* temp = head;
        while(index > 0){
            temp = temp->next;
            --index;
        }
        
        ListNode* tar = new ListNode(val);
        
        tar->next = temp->next;
        temp->next = tar;
        ++size;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size){
            return;
        }
        
        ListNode* temp = head;
        while(index > 0){
            temp = temp->next;
            --index;
        }
      
        ListNode* del = temp->next;
        temp->next = del->next;
        --size;
        delete del;
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */