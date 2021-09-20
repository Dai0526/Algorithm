/*
https://leetcode.com/problems/fraction-to-recurring-decimal/solution/

*/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {

    
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        
        // ignore denomitor = 0
        
        string ans = "";
        
        if(numerator > 0 ^ denominator > 0){
            ans += "-";
        }
        
        long n = abs(numerator);
        long d = abs(denominator);
        
        ans += to_string(n/d);
        
        long remain = n % d;
       
        if(remain == 0){
            return ans;
        }
        
        // working on decimal numbers
        ans += ".";

        unordered_map<long, int> rs;
        while (remain) {
            if (rs.find(remain) != rs.end()) {
                ans.insert(rs[remain], "(");
                ans += ')';
                break;
            }
            rs[remain] = ans.size();
            remain *= 10;
            ans += to_string(remain / d);
            remain %= d;
        }
        return ans;
    }
};