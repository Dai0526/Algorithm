/*
Naive solution to gengerate all numbers and get the max.

It is optimal

*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0){
            return 0;
        }
        
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        int max = 1;
        for(int i = 2; i < n + 1; ++i){
            if(i % 2 == 0){
                nums[i] = nums[i / 2];
            }else{
                int fst = (i - 1) / 2;
                nums[i] = nums[fst] + nums[fst + 1];
            }
            
            max = nums[i] > max ? nums[i] : max;
        }
        
        return max;
        
    }
};