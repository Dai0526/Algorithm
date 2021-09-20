/*
https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
In order to get min diff, the removed item must be first 3 min val or first 3 max vals;
1. Sort
2. some combinations for 3 combinations
remove 3 max [n - 4] - [0]
remove 3 min [n - 1] - [3]
remove 2 max 1 min [n - 3] - [1]
remove 1 max 2 min [n - 2] - [2]

or think about another way
0 remove will be [n - 1] - [0]
add 1 remove it will be min([n - 2] - n[0], [n-1] - n[1])

see which is better

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 5){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        // 0 remove
        int ans = numeric_limits<int>::max();
        
        for(int i = 0; i <= 3; ++i){
            ans = min(ans, (nums[n - 4 + i] - nums[i]));
        }
        
        return ans;
        
    }
};