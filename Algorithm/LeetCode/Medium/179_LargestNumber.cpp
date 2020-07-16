/*
https://leetcode.com/problems/largest-number/

We merge numbers one by one, each stage is rely on the result of previous one
example:
[3,30,34,5,9]

1-> 330 > 303 -> 330
2-> 34330 > 33034 -> 34330
3-> 534330 > 343305 -> 54330
4-> 954330

Step
1. Sort it base on num1:num2 > num2:num1
2. if leading(max) number nums[0] after sort is 0, then return "0"
3. concate all strings in nums, return it.

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(), 
             nums.end(), 
             [](int a, int b) { return to_string(a) + to_string(b) > to_string(b) + to_string(a); });
        
        
        if(nums[0] == 0){
            return "0";
        }

        string res= "";
        for(int n : nums){
            res += to_string(n);
        }
        
        return res;
    }
    
};