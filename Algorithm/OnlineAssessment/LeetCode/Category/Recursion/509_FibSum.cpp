/*
https://leetcode.com/problems/fibonacci-number/
*/
#include <vector>

using namespace std;

class Solution {
public:
    int fib_iter(int N) {
        if(N == 0 || N == 1){
            return N;
        }
        
        int sum = 0;
        int pre = 1;
        int prepre = 0;
        for(int i = 2; i < N + 1; ++i){
            sum = pre + prepre;
            prepre = pre;
            pre = sum;        
        }
        
        return sum;
    }
    
    int fib(int N) {
        if(N == 0 || N == 1){
            return N;
        }
        
        vector<int> lut(N + 1, 0);
        lut[0] = 0;
        lut[1] = 1;
        
        for(int i = 2; i < N + 1; ++i){
            lut[i] = lut[i-1] + lut[i-2];
        }
    
        return lut[N];
    }
};