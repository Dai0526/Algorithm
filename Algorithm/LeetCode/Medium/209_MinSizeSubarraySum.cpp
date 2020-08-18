/*
https://leetcode.com/problems/minimum-size-subarray-sum/
2 ptrs -> sliding window

*/
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 0){
            return 0;
        }
        
        int minVal = numeric_limits<int>::max();     
        int l = 0;
        int r = 0;
        int sum = nums[0];
        
        while(r < n && l <= r){
            
            if(sum < s){
                ++r;
                
                if(r >= n){
                    continue;
                }
                
                sum += nums[r];
            }else{
                minVal = min(r - l + 1, minVal);
                sum -= nums[l];
                ++l;
            }
        }
        return minVal == numeric_limits<int>::max() ? 0 : minVal;
    }
    
    int minSubArrayLen_bf(int s, vector<int>& nums) {

        int n = nums.size();
        
        if(n <= 0){
            return 0;
        }
        
        int minVal = numeric_limits<int>::max();
        
        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j = i; j < n; ++j){
                sum += nums[j];
                if(sum >= s){
                    minVal = min(j - i + 1, minVal);
                    break;
                }
            }
        }
        
        return minVal == numeric_limits<int>::max() ? 0 : minVal;
    }
};