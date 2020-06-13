/*

1. use linkedlist to achieve delete, or swap node in O(1)
2. use a hashMap to store listNode with value
*/

#include <map>

using namespace std;

class LRUCache {
    
struct ListNode {
    int key;
    int val;
    ListNode* next;
    ListNode* prev;
    
    ListNode(int k, int v):key(k),val(v){
        next = nullptr;
        prev = nullptr;
    }  
};
    
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(record.find(key) == record.end()){
            return -1;
        }
        
        // if found, move node to tail as the most recent one
        ListNode* target = record[key];
        
        MoveToLast(target);
        
        return target->val;
    }
    
    void put(int key, int value) {
        
        if(record.find(key) == record.end()){
            // add to last
            ListNode* curr = new ListNode(key, value);
            AddNodeToLast(curr);
            record[key] = curr;
            ++size;
            
            if(size > cap){
                // Remove first node
                RemoveLesatUsed();              
                --size;
            }
        }
        else{
            // if found, move node to tail as the most recent one
            ListNode* target = record[key];
            MoveToLast(target);
            target->val = value; //update value
        }
    }

    void RemoveLesatUsed(){
        ListNode* fst = head->next;
        head->next = fst->next;
        fst->next->prev = head;
                
        fst->next = nullptr;
        fst->prev = nullptr;  
        
        record.erase(fst->key);  
    }
    
    void AddNodeToLast(ListNode* node){
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;        
    }
    
    void MoveToLast(ListNode* node){
        // head -> a -> t -> ....-> z -> tail->nullptr
        // head <- a <- t -< ....<- z <- tail 
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        tail->prev->next = node;
        node->prev = tail->prev;
        tail->prev = node;
        node->next = tail;        
    }
    

private:
    
    int cap;
    int size;
    ListNode* head;
    ListNode* tail;
    map<int, ListNode*> record;
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */