#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        if(n == 0){
            return "";
        }
        
        vector<char> chars(26);
        for(int i = 0; i < 26; ++i){
            chars[i] = 'A' + i;
        }
        
        stringstream ss;
        
        while(n > 0){
            int remain = (n - 1) % 26;
            ss << chars[remain];
            n = (n - 1) / 26;
        }
        
        string str = ss.str();
        reverse(str.begin(), str.end());
        
        return str;
    }
};