#include <vector>

using namespace std;

class Solution {
public:
    
    /*
    average filter to smooth images
    
    */
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int row = img.size();
        int col = img[0].size();
        
        vector<vector<int>> out(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                out[i][j] = getPixel(i, j, img);
            }
        }
            
        return out;
    }
    
    int getPixel(int r, int c, const vector<vector<int>>& img){
        
        int row = img.size();
        int col = img[0].size();
        
        int sum = 0;
        int count = 0;
        
        for(int i = -1; i < 2; ++i){
            for(int j = -1; j < 2; ++j){
                
                int newR = r + i;
                int newC = c + j;
                
                // check if it is out of boundary
                if(newR < 0 || newR >= row || newC < 0 || newC >= col){
                    continue;
                }
                
                sum += img[newR][newC];
                ++count;
            }
        }
        
        return floor(sum / count);
    }
    
    
};