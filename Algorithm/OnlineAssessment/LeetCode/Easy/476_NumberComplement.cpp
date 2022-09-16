/*
https://leetcode.com/problems/number-complement/solution/

Do bit by bit
1. mask = 1
2. xor with number to flip bit
3. shift

*/

class Solution {
public:
    int findComplement(int num) {
        int target = num;
        int bit = 1;
        
        while(target != 0){
            
            num = num ^ bit; // flip bit
            bit = bit << 1;  // shift mask 
            target = target >> 1; // shift target
        }
        
        return num;
    }
};