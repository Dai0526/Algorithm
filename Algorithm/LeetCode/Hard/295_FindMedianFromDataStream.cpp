class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        m_fstHalf.push(num);
        // balance two head, such the top of fst had and top of snd half are adjacent numbers
        m_sndHalf.push(m_fstHalf.top());
        m_fstHalf.pop();
        
        if(m_fstHalf.size() < m_sndHalf.size()){  // balance size of two heaps, fst always >= snd size
            m_fstHalf.push(m_sndHalf.top());
            m_sndHalf.pop();
        }
        
    }
    
    double findMedian() {
        double median;
        
        if(m_fstHalf.size() > m_sndHalf.size()){
            median = m_fstHalf.top();
        }else{
            median = (m_fstHalf.top() + m_sndHalf.top()) / 2.0;
        }
        
        return median;
        
    }
    
private:
    
    // max heap
    priority_queue<int> m_fstHalf;
    // min heap
    priority_queue<int, vector<int>, greater<int>> m_sndHalf;
    
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */