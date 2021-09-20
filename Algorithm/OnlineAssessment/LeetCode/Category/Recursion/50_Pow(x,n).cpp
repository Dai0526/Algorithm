/*
https://leetcode.com/problems/powx-n/

可递归， 可循环

注意corner case
1. n == 0
1. n < 0
2. n is long long

        while(count > 0){
            if(count % 2 == 1){
                p *= x;
                --count;
            }else{
                x *= x;
                count /= 2;
            }
        }

递归做法
每次做 fastPow(x, n/2);

half = fastPow(x, N)
如果n是偶数，half * half
如果是奇数， half * half * x

*/

class Solution {
public:

    //递归
    double myPow_rec(double x, int n) {
        long long ln = n;
        if(ln < 0){
            x = 1 / x;
            ln = -ln;
        }
        
        return fastPow(x, ln);
    }
    
    double fastPow(double x, long long n){
        if(n == 0){
            return 1.0;
        }
                
        double half = fastPow(x, n / 2);
        
        if(n % 2 == 0){
            return half * half;
        }
        
        return half * half * x;
        
    }

    //循环
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
                
        double p = 1.0;
        long long count = n;
        
        if(n < 0){
            x = 1 / x;
            count = -count;
        }
        
        while(count > 0){
            if(count % 2 == 1){
                p *= x;
                --count;
            }else{
                x *= x;
                count /= 2;
            }
        }
        
        return p;
    }
};