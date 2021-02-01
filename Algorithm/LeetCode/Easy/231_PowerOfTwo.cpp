/*
Think about the bitwise shift operation

x & (x - 1) == 0 ?
x & (-x) ==  x


*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0){
            return false;
        }
        
        while(n != 1){
            if(n % 2 != 0){
                return false;
            }
            
            n = n / 2;
        }
        
        return true;
    }
};