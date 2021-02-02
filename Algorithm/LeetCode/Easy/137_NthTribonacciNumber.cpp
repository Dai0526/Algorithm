/*
1137 https://leetcode.com/problems/n-th-tribonacci-number/
*/
#include <vector>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
               
        
        if(n == 0){
            return 0;
        }
        
        if(n < 2){
            return 1;
        }
        
        vector<int> lut(n + 1, 0);
        lut[1] = 1;
        lut[2] = 1;
        
        for(int i = 3; i <= n; ++i){
            lut[i] = lut[i - 1] + lut[i - 2] + lut[i - 3];
        }
        
        return lut[n];
        
    }
};