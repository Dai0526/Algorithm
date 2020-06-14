
/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/


Core idea:

keep a ptr

move ptr only when i < 2 or nums[i] > nums[ptr - 2]

    e.g. 1  1  1  1  2  2
           ptr

    e.g. 1  1  1  1  2  2
              ptr   

    e.g. 1  1  1  1  2  2
              ptr    i  

set nums[idx] = nums[ptr], and move ptr
    e.g. 1  1  2  1  2  2
                 ptr    idx 

set nums[idx] = nums[ptr], and move ptr
    e.g. 1  1  2  2  2  2
                    ptr    idx 

ptr's index = 4, wihch is the length of new vector

*/


#include <vector>
using namespace std;

class Solution {
public:
    
    int removeDuplicates_mine(vector<int>& nums) {
        int size = nums.size();
        
        if(size < 3){
            return size;
        }

        int idx = 1;
        
        for(int i = 2; i < size; ++i){
            if(nums[i] != nums[idx - 1]){
                ++idx;
                nums[idx] = nums[i];
            }
        }
    
        return idx + 1;
    }
    
    int removeDuplicates(vector<int>& nums) {

        int idx = 0;
        
        for(int n : nums){
            if(idx < 2 || n > nums[idx - 2]){
                nums[idx] = n;
                ++idx;
            }
        }
                 
        return idx;
    }
};