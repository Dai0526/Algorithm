/*
https://leetcode.com/problems/longest-mountain-in-array/

*/
#include <vector>
using namespace std;
class Solution {
public:
    int longestMountain(vector<int>& A) {
        
        int n = A.size();
        
        if(n < 3){
            return 0;
        }
        
        int len = 0;
        int up = 0;
        int down = 0;
        
        for(int i = 1; i < A.size(); ++i){
            // when going down trend stop, find a hill, rest up and down
            if(down > 0 && A[i-1] < A[i] || A[i-1] == A[i]){
                up = 0;
                down = 0;
            }
            
            if(A[i-1] < A[i]){
                ++up;
            }
            
            if(A[i-1] > A[i]){
                ++down;
            }
            
            if(up > 0 && down > 0){
                len = max(len, up + down +1);
            }
            
            
        }
        
        return len;
    }
};