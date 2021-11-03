class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
           
        if(n == 1){
            return true;
        }
        
        vector<int> lut(n, -1);
        lut[0] = 1;
        
        for(int i = 0; i < n - 1; ++i){
            if(lut[i] == -1){
                return false;
            }
            
            for(int j = 1; j <= nums[i]; ++j){
                
                int idx = i + j;
                
                if(idx == n - 1){
                    return true;
                }
                
                lut[i + j] = 1;
            }
            
        }
        
        return false;
        
    }
};