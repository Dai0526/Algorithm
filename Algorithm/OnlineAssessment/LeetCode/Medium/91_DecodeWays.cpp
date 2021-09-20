/*

DP 

init a look up table

 2  2  6  7 
 1  2  3  3

Init


lut[i] = (s[i] + 10 * s[i-1] <= 26) ? lut[i-1] + 1 : lut[i-1];

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        
        int l = s.length();
        
        if(l == 0 || s[0] == '0'){
            return 0;
        }
         
        vector<int> lut(l + 1, 0);
        
        lut[0] = 1;
        lut[1] = 1;
        
        for(int i = 2; i < l + 1; ++i){
            int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            
            if(num >= 10 && num <= 26){
                lut[i] = s[i - 1] == '0' ? lut[i - 2] : lut[i - 1] + lut[i - 2];
            }else{
                lut[i] = s[i - 1] == '0' ? lut[i] = 0 : lut[i - 1];
            }
    
        }
        
        return lut[l];
        
    }
};