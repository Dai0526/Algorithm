/*
DP
https://leetcode.com/problems/unique-binary-search-trees/

case n = 7
take 3 as root, then we need to solve (1, 2) 3 (4, 5, 6)
(1, 2)
(4, 5, 6)
两组子问题，而 Foo(3) = g(1,2) * g(4, 5, 6)

1. init
lut(n + 1)
lut[0] = 1
lut[1] = 1;

2. transfer function
左边有j-1个数，右边有i - j个数
lut[i] += lut[j - 1] * lut[i - j]

最后返回lut[n]      
*/

#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> lut(n + 1, 0);
        
        lut[0] = 1;
        lut[1] = 1;
        
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <=i; ++j){
                lut[i] += lut[j - 1] * lut[i - j];
            }
        }
        
        return lut[n];
    }
};