
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int l = s.size();
        
        if(l == 0){
            return 0;
        }

        // eliminate leading ' '
        int idx = 0;
        while(s[idx] == ' '){
            ++idx;
        }
        
        //get sign
        int sign = 1;
        if(s[idx] == '-'){
            sign = -1;
            ++idx;
        }else if(s[idx] == '+'){
            ++idx;
        }
        
        long long ans = 0;
        
        while(idx < l && isDigit(s[idx])){
            ans = ans * 10 + (s[idx] - '0');
            
            if(ans > numeric_limits<int>::max()){
                if(sign == -1){
                    return numeric_limits<int>::min();
                }
                return numeric_limits<int>::max();
            }
            
            ++idx;
        }
             
        return (int)ans * sign;     
    }
    
    bool isDigit(char c){
        return (c >= '0' && c <='9');  
    }
    
};