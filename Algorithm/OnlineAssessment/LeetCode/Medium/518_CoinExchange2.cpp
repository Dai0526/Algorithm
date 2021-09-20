
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int len = amount + 1;
        vector<int> lut(len, 0);
        lut[0] = 1;
        
        for(int c : coins){
            for(int i = c; i < len; ++i){
                lut[i] = lut[i] + lut[i - c];
            }
        }
        
        return lut[amount];
    }
};