#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer unsorted array
     * @param k: an integer from 1 to n
     * @return: the kth largest element
     */
    int kthLargestElement2(vector<int> &nums, int k) {
        
        int len = nums.size();
        // 这里可以考虑一下边际情况，因为k必须要小于len
        
        // write your code here
        priority_queue<int> heap; // default is a max heap
        for(int i=0; i<len; ++i){
            heap.push(nums[i]);
        }
        
        for(int j=0; j< k - 1; ++j){
            heap.pop();
        }
        
        return heap.top();
    }
};