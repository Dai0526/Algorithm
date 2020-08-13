
/*
range from 1 to num/2


*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
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