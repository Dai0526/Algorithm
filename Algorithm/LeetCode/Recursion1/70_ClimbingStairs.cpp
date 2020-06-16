
/*
https://leetcode.com/problems/climbing-stairs/
本质上是斐波那契数列，可递归可DP
*/

#include <vector>

using namespace std;

class Solution {
public:
    
    int climbStairs(int n) {
        if(n == 0){
            return 0;
        }
        
        if(n == 1){
            return 1;
        }
    
        vector<int> lut(n + 1, 0);
        lut[1] = 1;
        lut[2] = 2;
        
        for(int i = 3; i < n + 1; ++i){
            lut[i] = lut[i - 1] + lut[i - 2];
        }
        
        return lut[n];
    }
    
    
    int climb_rec(int i, int n){
        if(i > n){
            return 0;
        }
        
        if(i == n){
            return 1;
        }
        
        return climb_rec(i + 1, n) + climb_rec(i + 2, n); 
    }
};