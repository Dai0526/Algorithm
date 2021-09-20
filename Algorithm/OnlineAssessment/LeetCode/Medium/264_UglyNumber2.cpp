/*
start from1, every times 2, 3, 5, take min

*/

class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> lut(n);
        lut[0] = 1;
        
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        
        for(int i = 1; i < n; ++i){
            lut[i] = min({ lut[idx2] * 2, lut[idx3] * 3, lut[idx5] * 5});
            if (lut[i] == lut[idx2] * 2) {
                ++idx2;
            }
            if (lut[i] == lut[idx3] * 3) {
                ++idx3;
            } 
            if (lut[i] == lut[idx5] * 5) {
                ++idx5;
            }
        }
        
        return lut[n - 1];
    }
};