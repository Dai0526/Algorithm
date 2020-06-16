/*

triangle
   0 1 2 3 4
0  1
1  1 1
2  1 2 1
3  1 3 3 1
4  1 4 6 4 1

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            return vector<int>{(1,1)};
        }
        
        if(rowIndex == 1){
            return vector<int>(2,1);
        }
        
        int size = rowIndex + 1;
        vector<vector<int>> grid(size, vector<int>(size, 1));
        
        for(int i = 2; i < size; ++i){
            for(int j = 1; j < i; ++j){
                grid[i][j] = grid[i-1][j-1] + grid[i-1][j];
            }
        }
        
        return grid[rowIndex];    
    }

    int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col)
            return 1;

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    vector<int> getRow_REC(int rowIndex) {
        vector<int> ans;

        for (int i = 0; i <= rowIndex; i++)
            ans.push_back(getNum(rowIndex, i));

        return ans;
    }
    
};