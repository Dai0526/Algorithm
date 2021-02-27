/*
https://leetcode.com/problems/broken-calculator/

work backwards

*/


class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X == Y){
            return 0;
        }
        
        if(X > Y){
            return X - Y;
        }
        
        if(Y % 2 == 1){
            return 1 + brokenCalc(X, Y + 1);
        }else{
            return 1 + brokenCalc(X, Y / 2);
        }
        
    }
};