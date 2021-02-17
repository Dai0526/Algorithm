/*
https://leetcode.com/problems/majority-element/submissions/
Two method

1. hashmap<int, int>    key = num, value = count

2. sort array, and majority is must be the mid element

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int num = numeric_limits<int>::min();
        
        for(int n : nums){
            if(count == 0){
                num = n;
                count = 1;
            }else if(n == num){
                ++count;
            }else{
                --count;
            }
        }
        
        return num;
    }
    
    int majorityElement_sort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() / 2];
    }
};