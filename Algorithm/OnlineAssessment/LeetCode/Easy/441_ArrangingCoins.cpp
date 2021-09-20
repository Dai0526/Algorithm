/*

(1 + n) * n / 2 = sum
n^2 + n - 2sum = 0;

n =  [-1 + sqrt(1 + 4 * (2sum))] /2
n = sqrt(1/4 + 2*sum) - 0.5
*/
#include <math.h>

class Solution {
public:
    int arrangeCoins(int n) {
        
        if(n < 3){
            return 1; 
        }
        
        int l = sqrt(0.25 + 2.0 * n) - 0.5;
        
        return l;
    }
};