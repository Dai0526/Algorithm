/*
Use the property of that the item on the same diagonal has the same value of (i - j)

*/

#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    
        // It should check mat first, we skip here
        
        unordered_map<int, priority_queue<int,vector<int>,greater<int>>> diags;

        int r = mat.size();
        int c = mat[0].size();
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                int nDiag = i - j;
                diags[nDiag].push(mat[i][j]);
            }
        }
        
        
        vector<vector<int>> sorted(r, vector<int>(c));
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                int nDiag = i - j;
                sorted[i][j] = diags[nDiag].top();
                diags[nDiag].pop();
            }
        }
        
        
        return sorted;
    }
};