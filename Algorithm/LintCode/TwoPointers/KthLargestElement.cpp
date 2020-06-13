/*
5. Kth Largest Element
https://www.lintcode.com/problem/kth-largest-element
Find K-th largest element in an array.

Example 1:
Input: n = 1, nums = [1,3,4,2]
Output: 4

Example 2:
Input: n = 3, nums = [9,3,2,4,8]
Output: 4
Challenge
O(n) time, O(1) extra memory.

Notice
You can swap elements in the array

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> &nums) {
        // write your code here
        if(nums.size() == 0){
            return -1;
        }
        
        return quickSelect(nums, 0, nums.size() - 1, n);
    }
    
    int quickSelect(vector<int> &nums, int start, int end, int n){
        if(start == end){
            return nums[start];
        }
        
        int i = start;
        int j = end;
        int pivot = nums[start + (end - start)/2];
        
        while(i<=j){
            while(i<=j && nums[i] > pivot){
                ++i;
            }
            
            while(i<=j && nums[j] < pivot){
                --j;
            }  
            
            
            if(i <= j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                
                ++i;
                --j;
            }
        }
        
        // 9 3 2 4 8
        // 2 3 9 4 8
  
        if(start + n - 1 <= j){
            return quickSelect(nums, start, j, n);
        }
        
        if(start + n - 1 >= i){
            return quickSelect(nums, i, end, n - (i - start));
        }
        
        return nums[j + 1];
    }
    
};