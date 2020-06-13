/*
https://leetcode.com/problems/merge-k-sorted-lists/
Serveral ways to do.
1. Use stl piority_queue

2. Implement merge 2 sorted lists,
    a. one by one
    b. divide and conquer



*/

#include <queue>
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
       
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        
        ListNode* result=new ListNode(0);
        ListNode* tmp=result;
        ListNode* cur;
        priority_queue<int,vector<int>,greater<int>> q;
        
        for(int i=0;i<lists.size();i++){
            ListNode* l=lists[i];
            while(l!=NULL){
                q.push(l->val);
                l=l->next;
            }
        }
        
        while(!q.empty()){
            cur=new ListNode(q.top());
            tmp->next=cur;
            tmp=tmp->next;
            q.pop();
        }
        
        return result->next;
    }
    
    
    ListNode* mergeKLists_slow(vector<ListNode*>& lists) {
        int nSize = lists.size();
        if(nSize == 0){
            return nullptr;
        }
        
        if(nSize == 1){
            return lists[0];
        }
        
        for(int i = 1; i < nSize; ++i){
            lists[0] = merge2Lists(lists[0], lists[i]);
        }
        
        return lists[0];
        
    }
    
    ListNode* merge2Lists(ListNode* a, ListNode* b){
        ListNode* head = new ListNode(0); //dummy
        ListNode* temp = head;
        while(a != nullptr && b != nullptr){
            if(a->val < b->val){
                temp->next = a;
                a = a->next;
            }else{
                temp->next = b;
                b = b->next;                
            }
            
            temp = temp->next;      
        }
        
        while(a != nullptr){
            temp->next = a;
            temp = temp->next;
            a = a->next;
        }
        
        while(b != nullptr){
            temp->next = b;
            temp = temp->next;
            b = b->next;
        }
        
        return head->next;
    }
};