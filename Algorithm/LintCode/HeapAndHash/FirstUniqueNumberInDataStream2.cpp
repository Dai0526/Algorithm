/*
960. First Unique Number in Data Stream II
https://www.lintcode.com/problem/first-unique-number-in-data-stream-ii/
We need to implement a data structure named DataStream. There are two methods required to be implemented:

void add(number) // add a new number
int firstUnique() // return first unique number
Example
Example 1:

Input:
add(1)
add(2)
firstUnique()
add(1)
firstUnique()
Output:
[1,2]
Example 2:

Input:
add(1)
add(2)
add(3)
add(4)
add(5)
firstUnique()
add(1)
firstUnique()
add(2)
firstUnique()
add(3)
firstUnique()
add(4)
firstUnique()
add(5)
add(6)
firstUnique()
Output:
[1,2,3,4,5,6]
Notice
You can assume that there must be at least one unique number in the stream when calling the firstUnique.

IDEA:
1. make sure it is to design a class to support these functions
2. what about time complexity for these two functions? 
3. How about space, if data stream is very long --> remove data
4. functionality -> can I remove data ---> find duplicated, directly remove
                or I have to keep all in record --> erase record from map, but use a vector to record

Have a Double linked list calss

-
map<int, Node*>
set<int> duplicated
vector<Node*> 
Node* head -> head of a unique item's list
Node* tail


*/


#include <vector>
#include <map>
#include <set>

using namespace std;

class DataStream {
    
struct Node{
    
    int val;
    Node* next;
    Node* prev;
    
    Node(int v) : val(v){
        next = nullptr;
        prev = nullptr;
    }
};
    
    
public:
    
    DataStream(){
        head = new Node(-1);
        tail = new Node(-1);
        
        head->next = tail;
        tail->prev = head;
    }
    
    ~DataStream(){
        
        for(auto &p : data){
            delete p;
        }
        
        delete head;
        delete tail;
    }
    
    /**
     * @param num: next number in stream
     * @return: nothing
     */
    void add(int num) {
        
        if(duplicated.find(num) != duplicated.end()){
            return; // skip if already appear in duplicated
        }
        
        // check if it is in map
        if(nodeMap.find(num) != nodeMap.end()){
            // remove Node from list
            Node* curr = nodeMap[num];
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            
            nodeMap.erase(num);
            
            // add it to duplicated set
            duplicated.insert(num);
        }else{
            
            Node* temp = new Node(num);
            nodeMap[num] = temp;
            
            // add to back of the list
            tail->prev->next = temp;
            temp->prev = tail->prev;
            temp->next = tail;
            tail->prev = temp;
            
            data.push_back(temp);
        }
        
    }

    /**
     * @return: the first unique number in stream
     */
    int firstUnique() {
        // write your code here
        return head->next->val;
    }
    
private:

    Node* head;
    Node* tail;
    
    map<int, Node*> nodeMap;
    set<int> duplicated;
    
    vector<Node*> data;
    
};