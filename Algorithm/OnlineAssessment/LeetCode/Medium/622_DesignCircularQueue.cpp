/*
622 Design Circular Queue
https://leetcode.com/problems/design-circular-queue/

*/
#include <vector>
using namespace std;
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vec.resize(k);
        head = 0;
        tail = 0;
        size = k;
        vecFull = false;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        
        vec[tail] = value;
        tail = (tail + 1) % size;
        
        if(head == tail && !vecFull){
            vecFull = true;
        }
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        
        head = (head + 1) % size;
        
        // check if full
        if(head != tail){
            vecFull = false;
        }
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()){
            return -1;
        }
        
        return vec[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()){
            return -1;
        }
        
        int rearIdx = (tail + size - 1) % size;
        return vec[rearIdx];
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(head == tail && !vecFull){
            return true;
        }
        
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return vecFull;
    }
    
private:
    vector<int> vec;
    int head;
    int tail;
    int size;
    // reset is the mark when the queue is empty
    // to differentiate from queue is full
    // because in both conditions (tail == head) stands
    bool vecFull;
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */