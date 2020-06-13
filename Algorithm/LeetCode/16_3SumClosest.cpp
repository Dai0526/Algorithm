/*
16. 3Sum Closest
https://leetcode.com/problems/3sum-closest/

1. Is it sorted?
two ptrs


*/
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
               
        int size = nums.size();
        
        if(size < 3){
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        int result = 0;
        int minDiff = numeric_limits<int>::max();
        
        for(int i = 0; i < size; ++i){
            int left = i + 1; 
            int right = size - 1;
            
            while(left < right){
                
                int sum = nums[i] + nums[left] + nums[right];
                
                int diff = sum - target;
                       
                if(diff == 0){
                    return sum;
                }else if(diff > 0){
                    --right;
                }else{
                    ++left;
                }
                
                if(minDiff > abs(diff)){
                    minDiff = abs(diff);
                    result = sum;
                } 
            }   
        }
        
        return result;
    }
};