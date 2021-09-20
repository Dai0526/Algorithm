/*
https://leetcode.com/problems/min-stack/
Follow up, make all operations to O(1)

Use two stacks:
1. stack
2. minstack 

*/
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
       
        // push to min stack
        if(m_minStk.empty() || m_minStk.top() > x){
            m_minStk.push(x);
        }else{
            m_minStk.push(m_minStk.top());
        }
        
        
        // push to container
        m_stack.push(x);
    }
    
    void pop() {
        m_minStk.pop();
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_minStk.top();
    }

private:
    stack<int> m_minStk;
    stack<int> m_stack;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */