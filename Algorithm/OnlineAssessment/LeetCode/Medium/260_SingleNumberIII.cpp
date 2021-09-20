/*
https://leetcode.com/problems/single-number-iii/solution/
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //create a bit mask which left over with x^y
        long long mask = 0;
        for(int n : nums){
            mask = mask ^ n;
        }
        
        int rmb = mask & (-mask);  // right most bit
        
        int a = 0, b = 0;
        for(int n : nums){
            if(n & rmb){
                a = a ^ n;
            }else{
                b = b ^ n;
            }
        }
        
        return vector<int>{a, b};
    }
};