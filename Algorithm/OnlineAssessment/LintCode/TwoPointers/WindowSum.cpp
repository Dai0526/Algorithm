/*
604. Window Sum
https://www.lintcode.com/problem/window-sum/
Given an array of n integers, and a moving window(size k), move the window at each iteration from the start of the array, find the sum of the element inside the window at each moving.

Example

Input：array = [1,2,7,8,5], k = 3
Output：[10,17,20]
Explanation：
1 + 2 + 7 = 10
2 + 7 + 8 = 17
7 + 8 + 5 = 20


1. Ask corner case / exception before doing problem
    a. k == 0
    b. k > size

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        
        if(k == 0){
            return vector<int>();
        }
        
        int nSize = nums.size();
        
        if(nSize < k){
            return vector<int>();
        }
        
        vector<int> sums(nSize - k + 1);
        
        int windowSum = 0;
        for(int i = 0; i < k; ++i){
            windowSum += nums[i];
        }
        
        sums[0] = windowSum;
        
        //slide window to right
        int left = 1;
        int right = k;
        
        while(right < nSize){
            windowSum = windowSum - nums[left - 1] + nums[right];
            sums[left] = windowSum;
            ++left;
            ++right;
        }
        
        return sums;
        
    }
};