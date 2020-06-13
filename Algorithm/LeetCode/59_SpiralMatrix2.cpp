/*
start 0,0
end   n/2, n % 2 == 0 ? n/2 - 1: n/2;

Iterate til i,j reach end point,
each time do 4 sides

*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        if(n == 0){
            return vector<vector<int>>();
        }
        
        int endrow = n / 2;
        int endcol = n % 2 == 0 ? n/2 - 1 : endrow;
        
        vector<vector<int>> spiral(n, vector<int>(n));
        spiral[0][0] = 1;
        
        int i = 0;
        int j = 0;
        
        int nLevel = 0;
        
        while(!(i == endrow && j == endcol)){
            // top side - left to right
            for(int c = j + 1; c < n - nLevel; ++c){
                spiral[i][c] = spiral[i][c - 1] + 1; 
                ++j;
            }
            
            // right side - up to down
            for(int r = i + 1; r < n - nLevel; ++r){
                spiral[r][j] = spiral[r - 1][j] + 1;  
                ++i;
            }
            
            // bottom side - right to left;
            for(int c = j - 1; c >= nLevel; --c){
                spiral[i][c] = spiral[i][c + 1] + 1;
                --j;
            }
            
            // left side - down to up
            for(int r = i - 1; r > nLevel; --r){
                spiral[r][j] = spiral[r + 1][j] + 1;
                --i;
            }
            
            ++nLevel;    
        }
        
        
        
        return spiral;
    }
};