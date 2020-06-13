/*
148. Sort Colors
https://www.lintcode.com/problem/sort-colors/
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Example
Input : [1, 0, 1, 2]
Output : [0, 1, 1, 2]
Explanation : sort it in-place

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Notice
You are not suppose to use the library's sort function for this problem.
You should do it in-place (sort numbers in the original array).


1. Rainbow sort
    just like quick sort, divide and conquar
    need 4 pointers, color_from, color_to, idx_from, idx_to
2. do partition, 3 pointers
    left, idx, right
    1. keep check when idx <= right !!!!
    2.  if c[idx] == 0, 
            sawp(left, idx)
            ++idx  move to next color
            ++left
        if c[idx] == 1
            ++idx move to next color
        if c[idx] == 2
            swap(idx, right)
            --right 
            don't move other pointer, because now idx is right, which has not been chcked.

3. Counting sort
    cout each color apperance, then overwrite array

*/


#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int size = nums.size();
        
        int left = 0;
        int right = size - 1;
        int idx = 0;
        
        while(idx <= right){
            if(nums[idx] == 0){
                swap(nums[left], nums[idx]);
                ++idx;
                ++left;
            }else if(nums[idx] == 1){
                ++idx;
            }else if(nums[idx] == 2){
                swap(nums[right], nums[idx]);
                --right;
            }
        }
        
    }
    
    
    void swap(int& idx1, int& idx2){
        int temp = idx1;
        idx1 = idx2;
        idx2 = temp;
    }
};