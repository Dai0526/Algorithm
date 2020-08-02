# Write your MySQL query statement below

/*
https://leetcode.com/problems/shortest-distance-in-a-line/

Write a query to find the shortest distance between two points in these points.
 

| x   |
|-----|
| -1  |
| 0   |
| 2   |
 

The shortest distance is '1' obviously, which is from point '-1' to '0'. So the output is as below:
 

| shortest|
|---------|
| 1       |

Note: Every point is unique, which means there is no duplicates in table point.
 

Follow-up: What if all these points have an id and are arranged from the left most to the right most of x axis?

1. The min distance only appers in the adjancent points.
Thus, sort by Id, JOIN on a.id = b.id - 1

SELECT MIN(ABS(a.x - b.x)) AS shortest
FROM point a, point b
WHERE a.id = b.id - 1;

*/

SELECT MIN(ABS(t1.x - t2.x)) AS shortest
FROM point t1 JOIN point t2
ON t1.x != t2.x;