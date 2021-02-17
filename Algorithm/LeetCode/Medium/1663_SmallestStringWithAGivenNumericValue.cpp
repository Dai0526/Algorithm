/*
https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

from right to left

init a vector with size n, filled with a
try to fill each one with max value

*/
#include <iostream>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans(n, 'a');
        k = k - n;
        
        for(int i = n - 1; i >=0 ; --i){
            if(k <= 0){
                break;
            }
            
            int val = k > 25 ? 25 : k;
            ans[i] = static_cast<char>(ans[i] + val);
            
            k -= val;
        }
        
        return ans;
    }
};