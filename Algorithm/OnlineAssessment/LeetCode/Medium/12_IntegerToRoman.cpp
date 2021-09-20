/*
brute force

*/

#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        
        stringstream ss;
        for(int i = 0; i < val.size(); ++i){
            while(num - val[i] >= 0){
                num -= val[i];
                ss << roman[i];
            }
        }
        
        return ss.str();
    }
};