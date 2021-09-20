/*
62. Search in Rotated Sorted Array
https://www.lintcode.com/problem/search-in-rotated-sorted-array/
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Example 1:
Input: [4, 5, 1, 2, 3] and target=1, Output: 2.

Example 2:
Input: [4, 5, 1, 2, 3] and target=0, Output: -1.
Challenge
O(logN) time

先和最右做比较，判断mid在哪个区间
1. 在左区间
        只有在 mid > target and target >= left 时 right = mid，
        其余情况都是 left = mid
2. 在右区间
        只有在 mid < target and target <= right 时 lert = mid，
        其余情况都是 right = mid

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // binary seasrch
        //skip corner case check
        if(A.size() == 0 ){
            return -1;
        }
        
        int left = 0;
        int right  = A.size() - 1;
        
        
        while(left + 1 < right){
            
            int mid = left + (right - left) / 2;
            
            if(A[mid] == target){
                return mid;
            }
            
            // use right side as boundary
            if(A[mid] < A[right]){
                if(A[mid] < target && target <= A[right]){
                    left = mid;
                }else{
                    right = mid;
                }
                
            }else{
                if(A[mid] > target && target >= A[left]){
                    right = mid;
                }else{
                    left = mid;
                }
            }
            
        }
        
        if(A[left] == target){
            return left;
        }
        
        if(A[right] == target){
            return right;
        }
        
        return -1;
        
    }
};