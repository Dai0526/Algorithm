/*
https://leetcode.com/problems/flip-string-to-monotone-increasing/
 0   0   1   1   0
*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int one = 0;
        int zero = 0;
        int l = s.length();
        
        for(int i = 0; i < l; ++i){
            if(s[i] == '0'){
                ++zero;
            }
        }
        
        int ans = min(l - zero, zero);
        
        int oneBefore = 0;
        int zeroAfter = zero;
        
        for(int i = 0; i < l; ++i){
            
            if(s[i] == '0'){
                --zeroAfter;

            }else{
                ++oneBefore;
            }
               
            // if find a 1, take it as start, total #flip = one before + zero after
            int flip = oneBefore + zeroAfter;
            ans = min(ans, flip);
        }
        
        return ans;
        
    }
};