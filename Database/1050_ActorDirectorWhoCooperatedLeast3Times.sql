/*
https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/
Write a SQL query for a report that provides the pairs (actor_id, director_id) where the actor have cooperated with the director at least 3 times.

Example:

ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+

Result table:
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
The only pair is (1, 1) where they cooperated exactly 3 times.
*/
/*
A dummy Solution

SELECT actor_id, director_id
FROM (SELECT actor_id, director_id, count(DISTINCT(timestamp)) AS cnt
        FROM ActorDirector
        GROUP BY actor_id, director_id) AS cntTable
WHERE cnt >= 3

*/


SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(timestamp) >= 3; # Timestamp is Primary key, it is unique