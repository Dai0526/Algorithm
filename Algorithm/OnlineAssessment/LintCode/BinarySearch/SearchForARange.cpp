/*
61. Search for a Range
https://www.lintcode.com/problem/search-for-a-range/
Given a sorted array of n integers, find the starting and ending position of a given target value.

If the target is not found in the array, return [-1, -1].

Example
Example 1:

Input:
[]
9
Output:
[-1,-1]

Example 2:

Input:
[5, 7, 7, 8, 8, 10]
8
Output:
[3, 4]
Challenge
O(log n) time.


*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> range(2,-1);
        
        int size = A.size();
        
        if(size == 0){
            return range;
        }
        
        
        int begin = findLeftBound(A, 0, size - 1, target);
        
        if(begin == -1){
            return range;
        }
        
        int end = findRightBound(A, begin, size - 1, target);
        
        range[0] = begin;
        range[1] = end;
        
        return range;
        
    }
    
    int findLeftBound(const vector<int>& A, int left, int right, int target){
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(A[mid] >= target){
                right = mid; 
            }else{
                left = mid;
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
    
    int findRightBound(const vector<int>& A, int left, int right, int target){
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(A[mid] <= target){
                left = mid; 
            }else{
                right = mid;
            }
        }
        
        if(A[right] == target){
            return right;
        }
    
        if(A[left] == target){
            return left;
        }
    
        return -1;
    }
    
    
};