/*
Sliding window by hash set
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // sliding window
        unordered_set<int> lut;
        
        for(int i = 0; i < n; ++i){
            int num = nums[i];
            if(lut.find(num) != lut.end()){
                return true;
            }
            
            lut.insert(num);
            // maintain window size
            if(lut.size() > k){
                lut.erase(nums[i-k]);
            }
            
        }
        
        return false;
    }
};