
/*
https://leetcode.com/problems/perfect-number/
range from 1 to num/2

There is an NlogN solution
*/

class Solution {
public:


    bool checkPerfectNumber(int num) {
        if(num < 2){
            return false;
        }
               
        int sum = 1;
            
        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                sum += i;

                if(i * i != num){
                    sum += num/ i;
                }
            }
        }
        
        return sum == num;
    }

    bool checkPerfectNumber_linear(int num) {
        if(num <= 0){
            return false;
        }
               
        int n = 1;
        int sum = 0;
        
        while(n < (num / 2) + 1){
            if(num % n == 0){
                sum += n;
            }
            
            ++n;
        }

        return sum == num;
    }
};