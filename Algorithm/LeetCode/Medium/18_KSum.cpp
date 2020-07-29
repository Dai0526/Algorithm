
/*
https://leetcode.com/problems/4sum/solution/

Let's do it in a K-Sum Manner by using two pointer

The idea is to keep reducing K util k = 2.


*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        return kSum(nums, target, 0, 4);
        
    }
    
    // recursion to reduce is to kSum
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> res;
        
        int n = nums.size();
        
        // cases that no need to go further
        if(start >= n){
            return res;
        }
        
        if(k == 2){
            return twoSum(nums, target, start);
        }
        
        for(int i = start; i < n - k + 1; ++i){
            if(i > start && nums[i] == nums[i - 1]){
                continue;
            }
            
            vector<vector<int>> temp = kSum(nums, target - nums[i], i + 1, k - 1);
            if(temp.size() == 0){
                continue;
            }
            
            for(vector<int>& vec : temp){
                vec.push_back({nums[i]});   
                res.push_back(vec);
            } 
        }
        
        return res;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int begin){
        // presorted
        vector<vector<int>> result;
        int l = begin;
        int r = nums.size() - 1;
        
        while(l < r){
            int sum = nums[l] + nums[r];
            
            if(sum < target){
                ++l;   
            }else if(sum > target){
                --r;
            }else{
                vector<int> temp(2);
                temp[0] = nums[l];
                temp[1] = nums[r];
                
                result.push_back(temp);

                --r;
                ++l;
                
                // remove duplicated
                while(l < r && nums[l] == nums[l - 1]){
                    ++l;
                }                
                while(l < r && nums[r] == nums[r + 1]){
                    --r;
                }
            }
            
        }
        
        return result;
        
    }
};