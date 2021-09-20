#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.compare(b) == 0){
            return -1;
        }
        
        return max(a.length(), b.length());        
    }
};