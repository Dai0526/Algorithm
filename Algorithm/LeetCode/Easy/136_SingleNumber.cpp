/*

https://leetcode.com/problems/single-number/

1. Use hash map
Time O(n)
Space O(n)

2.  Bit manipulation - XOR

a xor 0 = a
a xor a = 0

So all pair will be 0, and the remain xor 0 will be the one

*/

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int target = 0;
        for(int n : nums){
            target ^= n;
        }
        
        return target;
    }
};