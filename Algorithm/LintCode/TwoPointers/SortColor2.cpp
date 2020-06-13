/*
143. Sort Colors II
https://www.lintcode.com/problem/sort-colors-ii/
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example1
Input: 
[3,2,2,1,4] 
4
Output: 
[1,2,2,3,4]

Example2
Input: 
[2,1,1,2,2] 
2
Output: 
[1,1,2,2,2]
Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?

Notice
You are not suppose to use the library's sort function for this problem.
k <= n

1. can use idea of partition -> k - 1 partitions
2. like quick sort, recursion
3. divided and conqur
*/
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int size = colors.size();
        if(size < 2){
            return;
        }
        
        rainbowSort(colors, 0, size - 1, 1, k);
        
    }
    
    void rainbowSort(vector<int> &colors, int start, int end, int colorFrom, int colorTo){
        
        
        // recursion exit when partition to size = 1 
        if(start == end || colorFrom == colorTo){
            return; 
        }
        
        int left = start;
        int right = end;
        
        int pivotColor = colorFrom + (colorTo - colorFrom) / 2;
        
        while(left <= right){
            while(left <= right && colors[left] <= pivotColor){
                ++left;
            }
            
            while(left <= right && colors[right] > pivotColor){
                --right;
            }
            
            
            if(left <= right){
                int temp = colors[left];
                colors[left] = colors[right];
                colors[right] = temp;
                
                --right;
                ++left;
                
            }
        }
        
        
        // sort left partition
        rainbowSort(colors, start, right, colorFrom, pivotColor);
        rainbowSort(colors, left, end, pivotColor + 1, colorTo);
        
    }
    
};