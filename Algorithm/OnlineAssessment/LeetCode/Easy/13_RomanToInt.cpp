#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        
        if(l == 0){
            return 0;
        }
        
        unordered_map<char, int> romanMap;
        romanMap['I'] = 1;
        romanMap['V'] = 5;
        romanMap['X'] = 10;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['D'] = 500;
        romanMap['M'] = 1000;
        
        // initial value
        int value = 0;
        for(int i = 0; i < l - 1; ++i){
            int curr = romanMap[s[i]];
            int next = romanMap[s[i + 1]];
            
            if(curr >= next){
                value += curr;
            }else{
                value -= curr;
            }
        }
        
        
        value += romanMap[s[l - 1]];
        
        return value;
    }
};