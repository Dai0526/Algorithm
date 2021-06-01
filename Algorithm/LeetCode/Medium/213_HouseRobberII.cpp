class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        switch(n){
            case 0:
                return 0;
            case 1:
                return nums[0];
            case 2:
                return max(nums[0], nums[1]);
            default:
                break;
        }
        
        
        int amt1 = heist(0, n - 2, nums);
        int amt2 = heist(1, n - 1, nums);
        
        return max(amt1, amt2);
        
    }
    
    
    int heist(int begin, int end, const vector<int>& nums){
        int n = nums.size();
        
        vector<int> lut(n, 0);
        
        lut[begin] = nums[begin];
        lut[begin + 1] = max(nums[begin], nums[begin + 1]); 
        
        for(int i = begin + 2; i <= end; ++i){
            lut[i] = max(nums[i] + lut[i - 2], lut[i - 1]);
        }
        
        return lut[end];
    }
    
};