/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
Put all number to min heap

keep pop and sum up the left-th to right-th
*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
    
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        int mod = 1E9 + 7;
        
        for(int i = 0; i < nums.size(); ++i){
            int s = nums[i];
            pq.push(s);
            
            for(int j = i +1; j < nums.size(); ++j){
                s += nums[j];
                pq.push(s);
            }
        }
        
        int res = 0;
        for(int i = 0; i < right; ++i)
        {
            if(i >= left - 1)
                res += pq.top();
            pq.pop();
        }
        
        return res % mod;
    }
};