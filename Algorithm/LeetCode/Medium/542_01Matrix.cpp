/*
https://leetcode.com/problems/01-matrix/

QFA?
1. Can I directly modified on original matrix

IDEA:
Do BFS for each node, start from each zero, check neighbor, update distance
    if m[i][j] == 0 -> set dist[i][j] = 0 add to Queue

Since we want to find the nearest distance to 0,
whenever we go to a block whose current dist is greater than current dist + 1,
which means we get a new shortest distance from 0, thus update it.

                if(dist[newX][newY] > dist[x][y] + 1){
                    dist[newX][newY] = dist[x][y] + 1;
                    myQueue.push(pair<int,int>{newX,newY});
                }
    
*/
#include <vector>
#include <queue>
using namespace std;


class Solution {

    
private:
    
    const vector<int> DIRX{1, 0, -1, 0};
    const vector<int> DIRY{0, 1, 0, -1};
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        
        if(row == 0){
            return matrix;
        }
        
        int col = matrix[0].size();
        
        vector<vector<int>> dist(row, vector<int>(col, numeric_limits<int>::max()));      
        queue<pair<int, int>> myQueue; 
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(matrix[i][j] == 0){
                    dist[i][j] = 0;
                    myQueue.push(pair<int,int>{i,j});
                }
            }
        }
        
        while(!myQueue.empty()){
            pair<int,int> curr = myQueue.front();
            myQueue.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            for(int i = 0; i < 4; ++i){
                int newX = x + DIRX[i];
                int newY = y + DIRY[i];
                
                if(newX < 0 || newX >= row || newY < 0 || newY >= col){
                    continue;
                }
                
                // if newX,newY is greater then source + 1, then the shortest dist is source + 1
                if(dist[newX][newY] > dist[x][y] + 1){
                    dist[newX][newY] = dist[x][y] + 1;
                    myQueue.push(pair<int,int>{newX,newY});
                }
                
            }
            
        }
        
        return dist;
    }
};