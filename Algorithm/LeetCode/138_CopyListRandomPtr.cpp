/*
https://leetcode.com/problems/copy-list-with-random-pointer/
Simple solution

Do 2 iteration
1. clone all next node
2. point to Random Node

Need a way to find Random Node faster, better in O(1)
So use a map to record all added pointers

Thus can improve previous solution

Clone head
While head is not null, 
1. Find its next
    if next node in map
        set next ptr to it
    else node it map
        Create a new next node
        put in map
        set next
2. Find its Random
    if Random node in map, 
        set Random pointer to it
    else Random node not in map, 
        create a new Node, 
        put in map, 
        set Random

head = head.next


*/

#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    
    Node* CloneNode(Node* n, map<Node*, Node*>& rec){
        
        if(n == nullptr){
            return nullptr; 
        }
        
        if(rec.find(n) == rec.end()){
                // create a new node
            Node* temp = new Node(n->val);
            rec[n] = temp;
            return temp;

        }
        
        return rec[n];
                 
    }
    
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }
        
        map<Node*, Node*> nodesMap; // key is old node ref, value is cloned Node ref
        
        Node* curr = new Node(head->val);
        nodesMap[head] = curr;
        
        Node* pRef = head;  
        
        while(pRef != nullptr){
            
            curr->next = CloneNode(pRef->next, nodesMap);
            curr->random = CloneNode(pRef->random, nodesMap);
            curr = curr->next;
            pRef = pRef->next; 
            
        }
 
        return nodesMap[head];
    }
};