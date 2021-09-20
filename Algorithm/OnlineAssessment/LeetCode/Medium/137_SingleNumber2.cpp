/*
https://leetcode.com/problems/single-number-ii/solution/
1.
A simple way with extra memory is using hashmap,
time  O(n)
space O(n)

2. How do it inplace?
Bitwise operation, Learn that trick
XOR ^: 0 ^ x = x, x ^ x = 0 -> 奇数次时为x,偶数次为0

现在的问题是如何判断第一次碰到还是第二次碰到， 主题是用mask分出一次和三次
use two masks, thus if it occurs 3 times, it will ignore

change seen_once only if seen_twice is unchanged
change seen_twice only if seen_once is unchanged
*/

#include <map>

using namespace std;

class Solution {
public:
    int singleNumber_bit(vector<int>& nums) {
        int once = 0;
        int twice = 0;
        
        for(int n : nums){
            once = ~twice & (once ^ n);
            twice = ~once & (twice ^ n);
        }
        
        return once;
    }
    
    
    int singleNumber(vector<int>& nums) {
        map<int, int> counter;
        
        for(int n : nums){
            ++counter[n];
        }
        
        for(map<int,int>::iterator it = counter.begin(); it != counter.end(); ++it){
            if(it->second == 1){
                return it->first;
            }
        }
        
        return -1;
    }
};