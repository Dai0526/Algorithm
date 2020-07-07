
/*
https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

偶数 则正负对应收尾填充
奇数， 同上，中间为0

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> out(n, 0);
        for(int i = 1; i <= n / 2; ++i){
            out[i - 1] = i;
            out[n - i] = -i;
        }

        return out;        
    }
};