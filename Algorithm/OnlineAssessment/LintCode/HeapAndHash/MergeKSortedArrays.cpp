/*
486. Merge K Sorted Arrays
https://www.lintcode.com/problem/merge-k-sorted-arrays/
Given k sorted integer arrays, merge them into one sorted array.

Example 1:
Input: 
  [
    [1, 3, 5, 7],
    [2, 4, 6],
    [0, 8, 9, 10, 11]
  ]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

Example 2:
Input:
  [
    [1,2,3],
    [1,2]
  ]

Output: [1,1,2,2,3]
Challenge
Do it in O(N log k).

N is the total number of integers.
k is the number of arrays.

很多种解决方法
1. 不停调用合并两个有序数组， 可递归可循环
2. 用pirority_queue, 记住c++中是max heap, 构造函数时使用
std::priority_queue<int, std::vector<int>, std::greater<int>>使其变为min heap

*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        int nArray = arrays.size();
        
        if(nArray == 0){
            return vector<int>();
        }
        
        if(nArray == 1){
            return arrays[0];
        }
         
        vector<int> workingArray;
        
        for(int i = 0; i < nArray; ++i){
            workingArray = merge2SortedArrays(workingArray, arrays[i]);
        }
        
        return workingArray;
    }
    
    
    vector<int> merge2SortedArrays(vector<int>& a, const vector<int>& b){
        
        int sizeA = a.size();
        int sizeB = b.size();
        
        vector<int> merged;
        
        int ptA = 0;
        int ptB = 0;
        
        int smSize = sizeA < sizeB ? sizeA : sizeB;
        
        while(ptA < sizeA && ptB < sizeB){
            if(a[ptA] < b[ptB]){
                merged.push_back(a[ptA]);
                ++ptA;
            }else{
                merged.push_back(b[ptB]);
                ++ptB;
            }
            
        }
        
        if(ptA == sizeA){
            while(ptB < sizeB){
                merged.push_back(b[ptB]);
                ++ptB;
            }
        }
        
        if(ptB == sizeB){
            while(ptA < sizeA){
                merged.push_back(a[ptA]);
                ++ptA;
            }
        }
        
        return merged;
    }
};