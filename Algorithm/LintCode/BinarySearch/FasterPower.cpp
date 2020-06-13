/*
140. Fast Power
https://www.lintcode.com/problem/fast-power/
Calculate the an % b where a, b and n are all 32bit non-negative integers.

Example
For 231 % 3 = 2
For 1001000 % 1000 = 0
Challenge
O(logn)

Binary search, 利用 (a*b)%c = a%c * b%c
temp = a
每一次循环，temp = temp * temp;   -> a, a^2, a^4, a^8
凡是碰到
*/

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if(n == 0){
            return 1 % b;
        }
        
        if(n == 1){
            return a % b;
        }
        
        long long temp = a;
        long long result = 1;
        
        while(n > 0){
            if(n % 2 == 1){
                // if it is odd number
                result = result * temp % b;
            }
            
            temp = temp * temp % b;
            n = n / 2;
        }
        
        return result % 2;
    }
};