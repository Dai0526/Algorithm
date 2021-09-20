/*
https://leetcode.com/problems/flatten-2d-vector/
2D vector - brute force solution
use a queue

*/

class Vector2D {
public:
    Vector2D(vector<vector<int>>& v) {
        for(const vector<int>& vec : v){
            for(int n : vec){
                m_queue.push(n);
            }
        }
    }
    
    int next() {
        int n = m_queue.front();
        m_queue.pop();
        return n;
    }
    
    bool hasNext() {
        return !m_queue.empty();
    }

private:
    queue<int> m_queue;
    
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */