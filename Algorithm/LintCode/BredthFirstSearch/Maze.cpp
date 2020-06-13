/*
787. The Maze
https://www.lintcode.com/problem/the-maze/
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example 1:
Input:
map = 
[
 [0,0,1,0,0],
 [0,0,0,0,0],
 [0,0,0,1,0],
 [1,1,0,1,1],
 [0,0,0,0,0]
]
start = [0,4]， end = [3,2]
Output: false

Example 2:
Input:
map = 
[[0,0,1,0,0],
 [0,0,0,0,0],
 [0,0,0,1,0],
 [1,1,0,1,1],
 [0,0,0,0,0]
]
start = [0,4]， end = [4,4]
Output: true
Notice
1.There is only one ball and one destination in the maze.
2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
5.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.


思路：


*/


#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
     
     struct Point{
        int x;
        int y;
        int steps;
        
        Point(int xidx, int yidx) : x(xidx), y(yidx) {
            steps = 0;
        }
        
     };
     
    const int DIRS = 4;
    const vector<int> dX = {1, 0, -1, 0}; //r,d,l,up
    const vector<int> dY = {0, 1, 0, -1};
     
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {

        // Check some edge case
        int row = maze.size();
        int col = maze[0].size();
        
        int startX = start[0];
        int startY = start[1];
        
        int endX = destination[0];
        int endY = destination[1];
        
        // record visited point, avoid repeated
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        // queue for BFS
        std::queue<Point*> myQueue;
        
        Point* ptStart = new Point(startX, startY);    
        myQueue.push(ptStart);
        
        while(!myQueue.empty()){
            
            Point* pt = myQueue.front();
            myQueue.pop();
            
            int x = pt->x;
            int y = pt->y;
            
            if(x == endX && y == endY){
                return true;
            }
            
            for(int i = 0; i < DIRS; ++i){
                int nextX = x;
                int nextY = y;
                
                while(nextX >=0 && nextX < row && nextY >=0 && nextY < col && maze[nextX][nextY] == 0){
                    nextX += dX[i];
                    nextY += dY[i];
                }

                nextX -= dX[i];
                nextY -= dY[i];

                if(!visited[nextX][nextY]){
                    Point* temp = new Point(nextX, nextY);
                    myQueue.push(temp);
                    visited[nextX][nextY] = true;
                }
            }         
        }
        
        
        return false;
    }
};