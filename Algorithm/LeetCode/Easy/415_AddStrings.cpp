#include <iostream>
#include <sstream>



using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        
        stringstream ss;
        
        while(i >=0 || j >=0){
            int sum = 0;
            if(i >= 0){
                sum += num1[i] - '0';
                --i;
            }
            
            if(j >= 0){
                sum += num2[j] - '0';
                --j;
            }
            
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ss << to_string(sum);
        }
        
        if(carry == 1){
            ss << "1";
        }
        
        string ans = ss.str();
        reverse(ans.begin(), ans.end());
        return ans;
            
    }
};