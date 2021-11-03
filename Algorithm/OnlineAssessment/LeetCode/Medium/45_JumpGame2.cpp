class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
           
        if(n == 1){
            return 0;
        }
        
        vector<int> lut(n, numeric_limits<int>::max());
        lut[0] = 0;
        
        for(int i = 0; i < n - 1; ++i){
            if(lut[i] == numeric_limits<int>::max()){
                return 0;
            }
            
            for(int j = 0; j <= nums[i]; ++j){      
                int idx = i + j; 
                
                if(idx >= n){
                    break;
                }
                
                lut[idx] = min(lut[idx], lut[i] + 1);
                ++idx;
            }
            
        }
        
        return lut[n - 1];
        
    }
};