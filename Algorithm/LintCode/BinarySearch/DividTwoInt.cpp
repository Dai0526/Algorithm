/*
414. Divide Two Integers
https://www.lintcode.com/problem/divide-two-integers/
Divide two integers without using multiplication, division and mod operator.
If it will overflow(exceeding 32-bit signed integer representation range), return 2147483647
The integer division should truncate toward zero.

Example 1:
Input: dividend = 0, divisor = 1
Output: 0

Example 2:
Input: dividend = 100, divisor = 9
Output: 11

思路
二分法 -> 递进二分的思路
当2 * curr > remain -> remain = remain - sum, 重置sum
可以用非递归，也可以用递归
非递归思路需要好好考虑


*/


#include <algorithm>
#include <limits>
using namespace std;
class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
     
    long divideHelper(long ldvd, long ldvs){
        if(ldvd < ldvs){
            return 0;
        }
        
        long sum = ldvs;
        long mult = 1;
        
        while(sum + sum < ldvd){
            sum += sum;
            mult += mult;
        }
        
        return mult + divideHelper(ldvd - sum, ldvs);
    }
     
    int divide(int dividend, int divisor) {

        // get signed
        int sign = 1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            sign = -1;
        }
        
        // max
        long long ldvd = abs((long)dividend);
        long long ldvs = abs((long)divisor);
        
        if(ldvd < ldvs || ldvd == 0){
            return 0;
        }
        
        if(ldvd == ldvs){
            return sign;
        }

        long res = sign * divideHelper(ldvd, ldvs);
        
        if(res > numeric_limits<int>::max()){
            return numeric_limits<int>::max();
        }
        
        if(res < numeric_limits<int>::min()){
            return numeric_limits<int>::min();
        }
        
        return (int)res;
    }
};