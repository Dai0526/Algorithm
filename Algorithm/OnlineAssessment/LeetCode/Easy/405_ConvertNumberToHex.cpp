#include <sstream>
#include <algorithm>
#include <iostream>

class Solution {
public:
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        
        const int DIV = 16;
        const string HEX_MAPPING_STR = "0123456789abcdef";
        
        stringstream ss;
        // convert to 2's complement rep for negative number
        unsigned int temp = num; 
        
        while(temp > 0){
            int nIdx = temp % DIV;
            char cHex = HEX_MAPPING_STR[nIdx];
            ss << cHex;
            temp = temp / DIV;
        }
        
        string ans = ss.str();
        reverse(ans.begin(), ans.end()); // in reverse order
        
        return ans;
    }
};