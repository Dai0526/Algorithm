
/*
788. The Maze II
https://www.lintcode.com/problem/the-maze-ii/
There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.

The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.

Example
Example 1:
	Input:  
	(rowStart, colStart) = (0,4)
	(rowDest, colDest)= (4,4)
	0 0 1 0 0
	0 0 0 0 0
	0 0 0 1 0
	1 1 0 1 1
	0 0 0 0 0

	Output:  12
	
	Explanation:
	(0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(2,0)->(2,1)->(2,2)->(3,2)->(4,2)->(4,3)->(4,4)

Example 2:
	Input:
	(rowStart, colStart) = (0,4)
	(rowDest, colDest)= (0,0)
	0 0 1 0 0
	0 0 0 0 0
	0 0 0 1 0
	1 1 0 1 1
	0 0 0 0 0

	Output:  6
	
	Explanation:
	(0,4)->(0,3)->(1,3)->(1,2)->(1,1)->(1,0)->(0,0)
	
Notice
1.There is only one ball and one destination in the maze.
2.Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
3.The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
4.The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.



[[0,0,0,1,1,1,1,1],[0,1,0,0,0,0,0,0],[0,1,1,1,1,1,1,0],[0,0,0,0,0,0,0,0]]
[3,0]
[1,2]


[[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]]
[0,4]
[4,4]

1. BFS， 从起点出发，然后四个方向一个一个尝试，每次碰壁检查是不是终点，如果不是，把这阶段停止的点放入Queue中。
每次while循环检查Queue是否为空，然后把Queue中的每个candidate都做一遍检查，再去进行下一次Queue的while循环，很重要，
因为要遍历整个宽度。

因为要求最小，所以每次停止的点药记录步数， 打擂台。

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
     * @return: the shortest distance for the ball to stop at the destination
     */
     
    struct Point{
        int x;
        int y;
        int step;
      
        Point(int idxx, int idxy):x(idxx), y(idxy){
            step = 0;
        }
      
    };
    
    const int DIR_NUM = 4;
    const vector<int> DIR_X{1, 0, -1, 0}; // right, down, left, up
    const vector<int> DIR_Y{0, 1, 0, -1};
     
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int row = maze.size();
        int col = maze[0].size();
        
        int endX = destination[0];
        int endY = destination[1];
        
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        queue<Point*> myQueue;
        Point* startPt = new Point(start[0], start[1]);
        
        myQueue.push(startPt);
        visited[start[0]][start[1]] = true;
        
        int minStep = numeric_limits<int>::max();
        bool reachable = false;
        
        while(!myQueue.empty()){
            
            int qSize = myQueue.size();
            //cout<< "qsize = " << qSize << endl;
            for(int i = 0; i< qSize; ++i){
                
                Point* pt = myQueue.front();
                myQueue.pop();
            
                int x = pt->x;
                int y = pt->y;
                int prev_steps = pt -> step;
            
            
                for(int j = 0; j < DIR_NUM; ++j){
                    // required keep move until valid
                    int nStep = 0;
                    int nextX = x;
                    int nextY = y;
                
                    while(nextX >= 0 && nextX < row && nextY >= 0 && nextY < col && maze[nextX][nextY] == 0){
                        nextX += DIR_X[j];
                        nextY += DIR_Y[j];
                        ++nStep;
                    }
                
                    // one step more, thus subtract one
                    nextX -= DIR_X[j];
                    nextY -= DIR_Y[j];
                    --nStep;
                    
                    
                    if(nextX == endX && nextY == endY){
                        reachable = true;
                        if(prev_steps + nStep < minStep){
                            minStep = prev_steps + nStep;
                        }
                        continue;
                    }
                    
                    
                    if(visited[nextX][nextY] == false){
                        //cout<<"x: " << nextX << ", y: " << nextY << ", step: " << nStep << endl;
                        Point* temp = new Point(nextX, nextY);
                        temp -> step = prev_steps + nStep;
                        myQueue.push(temp);
                        visited[nextX][nextY] = true;
                    }
                }
            }
        }
        
        if(reachable){
            return minStep;
        }
        
        return -1;
        
    }
};