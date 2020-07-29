/*
https://leetcode.com/problems/3sum/submissions/

like 2 sum.
Keep in mind of 
1. edge cases
2. remove duplicated for fst number
3. remove duplicated when one pair is found

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> res;
        
        if(nums.size() < 3){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; ++i){
            
            // remove duplicated
            if(i > 0 && nums[i] == nums[i -1]){
                continue;
            }
            
            int n = nums[i];
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while(l < r){         
                int sum = n + nums[l] + nums[r];
                
                if(sum > 0){
                    --r;     
                }else if(sum < 0){
                    ++l;    
                }else{
                    vector<int> temp(3);
                    temp[0] = n;
                    temp[1] = nums[l];
                    temp[2] = nums[r];
                    
                    res.push_back(temp);
                    
                    ++l;
                    --r;
                    
                    // remove duplicated
                    while(l < r && nums[r] == nums[r + 1]){
                        --r;
                    }
                    
                    while(l < r && nums[l] == nums[l - 1]){
                        ++l;
                    }
                }      
            }        
        }
        return res;
    }
};