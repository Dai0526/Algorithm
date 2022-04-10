/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/submissions/
keep a cap  = k's max heap

*/

#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        cap = k;
        for(int n : nums){
            add(n);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > cap){
            pq.pop();
        }
        
        return pq.top();
    }
    
private:
    int cap;
    <int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */