#include <queue>

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        m_windowSize = size;
        m_sum = 0;
    }
    
    double next(int val) {
        if(m_window.size() < m_windowSize){
            m_window.push(val);
            m_sum += val;
        }else{
            m_sum = m_sum - m_window.front() + val;
            m_window.pop();
            m_window.push(val);
        }
        
        return m_sum / m_window.size();
    }
    
private:
    
    queue<int> m_window;
    double m_sum;
    int m_windowSize;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */