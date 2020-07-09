
/*
https://leetcode.com/problems/implement-queue-using-stacks/

two stacks one empty, just for holding items.

push - push to stk1
pop - peak from stack 2 and pop, reuturn
peek - if stack2 not empty, top from stk2. If stack2 empty, pop and push everything from stk1 to stk2.

*/

#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
        ++size;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int n = peek();
        stk2.pop();
        --size;
        
        return n;
        
    }
    
    /** Get the front element. */
    int peek() {
       if(!stk2.empty()){
           return stk2.top();
       }
        
        while(!stk1.empty()){
            int num = stk1.top();
            stk2.push(num);
            stk1.pop();
        }
        
        return stk2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }

private:
    stack<int> stk1; // real stack
    stack<int> stk2; // function as queue
    
    int size;
    

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */