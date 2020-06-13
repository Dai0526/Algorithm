/*
428. Pow(x, n)
https://www.lintcode.com/problem/powx-n/
Implement pow(x, n). (n is an integer.)

Example 1:
Input: x = 9.88023, n = 3
Output: 964.498

Example 2:
Input: x = 2.1, n = 3
Output: 9.261

Example 3:
Input: x = 1, n = 0
Output: 1

Challenge
O(logn) time

Notice
You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.

pow(x,n)
n不停整除2, 偶数情况下 x *= x;
奇数为两种情况，
1.计算过程中
2.最后结算

*/

class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // corner cases
        if(n == 0){
            return 1.0;
        }
        
        if(x == 0.0){
            return 0.0;
        }
            
        long long t = n;
        // deal with negative value
        if(t < 0){
            x = 1/x;
            t = -t;
        }
        
        // cumalated multiply
        double out = 1.0;
        while(t != 0){
            if(t % 2 == 1){
                out *= x;
                --t;
            }else{
                x *= x;
                t= t/2;
            }
        }  
        return out;
    }
    
};