/*
461. Kth Smallest Numbers in Unsorted Array
https://www.lintcode.com/problem/kth-smallest-numbers-in-unsorted-array/
Find the kth smallest number in an unsorted integer array.

Example
Example 1:

Input: [3, 4, 1, 2, 5], k = 3
Output: 3
Example 2:

Input: [1, 1, 1], k = 2
Output: 1
Challenge
An O(nlogn) algorithm is acceptable, if you can do it in O(n), that would be great.

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        // write your code here
        
        int nSize = nums.size();
        
        if(k > nSize || nSize == 0){
            return -1;
        }
        
        return quickSelect(nums, 0, nSize - 1, k);
        
    }
    
    
    int quickSelect(vector<int> &nums, int start, int end, int k){
        
        // exit
        if(start == end){
            return nums[start];
        }
        
        int mid = start + (end - start) / 2;
        int pivot = nums[mid];
        
        int i = start;
        int j = end;
        
        while(i <= j){
            // move i j to num[i] > num[j]
            while(i <= j && nums[i] < pivot){
                ++i;
            }
            
            while(i <= j && nums[j] > pivot){
                --j;
            }
            
            if(i<=j){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                
                --j;
                ++i;
            }
        }
        
        
        //binary search to find next start and end
        if(start + k - 1 <= j){
            quickSelect(nums, start, j, k);
        }
        
        if(start + k - 1 >= i){
            quickSelect(nums, i, end, k - (i - start));
        }
        
        return nums[k - 1];
        
    }
    
};