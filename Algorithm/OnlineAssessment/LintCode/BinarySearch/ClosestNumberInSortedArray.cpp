/*
459. Closest Number in Sorted Array
https://www.lintcode.com/problem/closest-number-in-sorted-array/
Given a target number and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to the given target.

Return -1 if there is no element in the array.

Example 1:
Input: [1, 2, 3] , target = 2, Output: 1.

Example 2:
Input: [1, 4, 6], target = 3, Output: 1.

Example 3:
Input: [1, 4, 6], target = 5, Output: 1 or 2.

Challenge
O(logn) time complexity.

Notice
There can be duplicate elements in the array, and we can return any of the indices with same value.

*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        int nSize = A.size();
        
        int left = 0;
        int right = nSize - 1;
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(abs(A[mid] - target) > abs(A[mid+1] - target)){
                left = mid;
            }else{
                right = mid;
            }
        }
        

        if(abs(A[left] - target) < abs(A[right] - target)){
            return left;
        }else{
            return right;
        }
        
    }
    
    
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  