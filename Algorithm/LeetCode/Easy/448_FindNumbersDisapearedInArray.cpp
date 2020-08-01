/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
1. O(n) space way is to use a vector or map
mark visited, then return unvisited

O(n) time and O(1) space

*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // if we can modified nums
        int n = nums.size();
        
        for(int i = 0; i < n; ++i){
            // get where that numbers shold be 
            int idx = abs(nums[i]) - 1;
            // mark apperad to be negative
            nums[idx] = nums[idx] > 0? -nums[idx] : nums[idx];   
        }
         
         
        vector<int> res;
        // that have positive magnitude in the array
        for (int i = 0; i < n; i++) {
            
            if (nums[i] > 0) {
                res.push_back(i+1);
            }
        }
        return res;
    }
    
    vector<int> findDisappearedNumbers_space(vector<int>& nums) {
        // if we can modified nums
        int n = nums.size();
        
        vector<int> ref(n, 0);

        for(int n : nums){
            ++ref[n - 1];
        }
        
        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(ref[i] == 0){
                res.push_back(i+1);
            }
        }
        
        return res;
    }
};