/*
Easiest way is to utilize STL stack

Fastest way is to use a hashmap, and double Linklist 

struct cmpByStringLength {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

// ...
std::map<std::string, std::string, cmpByStringLength> myMap;


ordered map, such that the max item is always the map.end() iter's

*/

#include <stack>
#include <algorithm>

using namespace std;

class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {

    }
    
    void push(int x) {
        m_stk.push(x);
        
        if(m_maxStk.empty()){
            m_maxStk.push(x);
        }else{
            int maxItem = max(x, m_maxStk.top());
            m_maxStk.push(maxItem);
        }
    }
    
    int pop() {
        m_maxStk.pop();
        int val = m_stk.top();
        m_stk.pop();
        return val;
    }
    
    int top() {
        return m_stk.top();
    }
    
    int peekMax() {
        return m_maxStk.top();
    }
    
    int popMax() {
        int maxItem = m_maxStk.top();
        stack<int> temp;
        while(m_stk.top() != maxItem){
            temp.push(m_stk.top());
            pop();
        }
        
        // remove from stack
        pop();
        
        while(!temp.empty()){
            push(temp.top());
            temp.pop();
        }
        return maxItem;
    }
private:
    stack<int> m_stk;
    stack<int> m_maxStk;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */