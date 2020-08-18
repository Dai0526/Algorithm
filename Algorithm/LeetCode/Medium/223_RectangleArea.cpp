/*
Math problem

area1 + area2 - shaded area

*/
#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        // rect 1
        //int w1 = C - A;
        //int h1 = D - B;
        
        long long s1 = (C - A) * (D - B);
        
        // rect 2
        //int w2 = G - E;
        //int h2 = H - F;
        long long s2 = (G - E) * (H - F);
        
        //no overlapped
        if(A >= G || E >= C || H <= B || F >= D){
            return s1 + s2;
        }
        
        // overlapped 
        return s1 + s2 - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        
    }
};