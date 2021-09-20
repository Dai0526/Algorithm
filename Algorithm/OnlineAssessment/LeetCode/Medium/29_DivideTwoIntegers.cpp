/*
https://leetcode.com/problems/divide-two-integers/
递进二分法
binary search
当 2 * curr > remain -> remain = remain - sum, 重置sum

e.g.  10 / 3
   dvs  rem  count
1-> 3   7      1
2-> 6   1      2
3-> 0
For Exponential growing, recursively doing: 
    
        long long sum = ldvs;
        long long mult = 1;
        
        while(sum + sum < ldvd){
            sum += sum;
            mult += mult;
        }
        
        return mult + divideHelper(ldvd - sum, ldvs);
    
        
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
        
        long long ldvd = abs((long)dividend);
        long long ldvs = abs((long)divisor);
        
        // corner case - 0
        if(ldvd < ldvs || ldvd == 0){
            return 0;
        }
        
        // corner case - 1
        if(ldvd == ldvs){
            return sign;
        }
        
        long long res = sign * divideHelper(ldvd, ldvs);
        
        // cornder case
        if(res > numeric_limits<int>::max()){
            return numeric_limits<int>::max();
        }
       
        if(res < numeric_limits<int>::min()){
            return numeric_limits<int>::min();
        }
        
        return res;
    }
    
    long long divideHelper(long long ldvd, long long ldvs){
        if(ldvd < ldvs){
            return 0;
        }   
        
        long long sum = ldvs;
        long long mult = 1;
        
        while(sum + sum < ldvd){
            sum += sum;
            mult += mult;
        }
        
        return mult + divideHelper(ldvd - sum, ldvs);
    }
};