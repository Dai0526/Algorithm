#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue_in.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int val = top();
        
        while(queue_in.size() != 1){
            queue_out.push(queue_in.front());
            queue_in.pop();
        }
              
        queue_in.pop();
        
        // switch 2 queues
        swap(queue_in, queue_out);
        
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return queue_in.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_in.empty();
    }
    
    void swap(queue<int>& q1, queue<int>& q2){
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
private:
    queue<int> queue_in; // hold top items
    queue<int> queue_out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */