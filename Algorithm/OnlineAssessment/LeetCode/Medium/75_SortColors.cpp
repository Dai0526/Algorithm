/*
https://leetcode.com/problems/sort-colors/solution/
partition
0,1,2
Three pointer:
    left = 0
    idx = 0
    right = size - 1

1. nums[idx] == 0
        swap left and idx
        ++left
        ++idx
2. nums[idx] == 1
        ++idx

3. nums[idx] == 2
        swap idx, right
        --right


*/
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 0 || size == 1){
            return;
        }
        
        int left = 0;
        int idx = 0;
        int right = size - 1;
        
        while(idx <= right){
            if(nums[idx] == 0){
                swap(nums[idx], nums[left]);
                ++left;
                ++idx;
            }else if(nums[idx] == 2){
                swap(nums[idx], nums[right]);
                --right;
            }else{
                ++idx;
            }      
        }
    }
    
    void swap(int& a, int&b){
        int temp = a;
        a = b;
        b = temp;
    }
};