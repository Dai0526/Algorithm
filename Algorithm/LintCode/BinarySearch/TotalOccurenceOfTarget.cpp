/*
462. Total Occurrence of Target
https://www.lintcode.com/problem/total-occurrence-of-target/
Given a target number and an integer array sorted in ascending order. Find the total number of occurrences of target in the array.

Example1:
Input: [1, 3, 3, 4, 5] and target = 3, 
Output: 2.

Example2:
Input: [2, 2, 3, 4, 6] and target = 4, 
Output: 1.

Example3:
Input: [1, 2, 3, 4, 5] and target = 6, 
Output: 0.
Challenge
Time complexity in O(logn)

两种方法，找到一边，然后朝另一边一个个去找

这里用的是两边 二分分别找左右边，然后相减 + 1。
第二遍二分可以用之前找到的一边为区间进行找更为优化

*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: A an integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int totalOccurrence(vector<int> &A, int target) {
        // 2 ways to do it, here we use to bfs to find boundary, then find length
        int size = A.size();
        
        if(size == 0){
            return 0;
        }
        
        int start = findLeftBound(A, 0, size - 1, target);
        
        if(start == -1){
            return 0;
        }
        
        int end = findRightBound(A, start, size - 1, target);
        
        if(end == -1){
            return 0;
        }
        
        return end - start + 1;
  
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