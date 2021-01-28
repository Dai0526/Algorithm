/*
Analysis the properties:

f(0) = 0
f(1) = 1          (f(0) << 1) + 1
f(2) = 110        (f(1) << 2) + 2
f(3) = 11011      (f(2) << 2) + 3
f(4) = 11011100   (f(3) << 3) + 4
...
f(d) = f(d - 1) << len(d) + d

l be d's length of binary form,

f(d + 1) = f(d) << l + (d + 1)

*/
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD_BASE = 1E9 + 7;
        long long ans = 0;
        
        for(int i = 1; i <= n; ++i){
            long long len = log2(i) + 1;
            ans = ((ans << len) % MOD_BASE + i) % MOD_BASE;
            
        }
        
        return ans;
    }

};