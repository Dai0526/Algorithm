
/*
dp - compare each 3 arithmetics

if(src[i] - src[i-1] == src[i-1] - src[i-2])
lut[i] = lut[i] + 1

them sum all in lut

*/
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        vector<int> lut(n, 0);
        
        int sum = 0;
        
        for(int i = 2; i < n; ++i){
            if(A[i] - A[i - 1] == A[i - 1] - A[i -2]){
                lut[i] = 1 + lut[i - 1];
                sum += lut[i];
            }
        }
        
        return sum;
        
    }
};