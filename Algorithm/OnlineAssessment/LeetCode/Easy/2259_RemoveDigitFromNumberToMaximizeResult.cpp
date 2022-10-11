/*
https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

if remove a digit, and next digit is greater than the one removed, which means
remove it increase the value.

We start from left, thus, the earlier it met the above condition, the larger it will be.

Find that index, and do a string concatenation. 

*/

#include <sstream>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {

        int idx, len = number.size();
        for (int i = 0; i < len; i++) {
            if (number[i] != digit) {
                continue;   
            }
            //12121
            idx = i;
            if (number[i+1] > number[i]) {
                break;
            }

        }
        return number.substr(0, idx) + number.substr(idx + 1);
    }
};

