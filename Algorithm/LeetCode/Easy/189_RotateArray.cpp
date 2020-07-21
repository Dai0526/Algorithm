/*
https://leetcode.com/problems/rotate-array/submissions/

Multiple ways to do it
For O(1) space
1. Reverse string k  = 3
arry         1  2  3  4  5  6
rev          6  5  4  3  2  1
rev offet    6  5  4  1  2  3
rev offet    4  5  6  1  2  3

2. Cyclic Replacements
One rotation need to change 3 items position
e.g.  move 2

index  0  1  2  3  4  5
arry   1  2  3  4  5  6
       5  6  1  2  3  4
      start = idx
      do {
        int next = (idx + k) % nums.length;
        int temp = nums[next];
        nums[next] = prev;
        prev = temp;
        idx = next;
        count++;
      } while (start != idx);       
      
       
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // shift to right, k is positive
        int n = nums.size();
        
        if(n < 2){
            return;
        }
        
        int shift = k % n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + shift);
        reverse(nums.begin() + shift, nums.end());
    }
    
};