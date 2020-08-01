/*
https://leetcode.com/problems/create-a-session-bar-chart/
You want to know how long a user visits your application. You decided to create bins of "[0-5>", "[5-10>", "[10-15>" and "15 minutes or more" and count the number of sessions on it.

Write an SQL query to report the (bin, total) in any order.

The query result format is in the following example.

Sessions table:
+-------------+---------------+
| session_id  | duration      |
+-------------+---------------+
| 1           | 30            |
| 2           | 199           |
| 3           | 299           |
| 4           | 580           |
| 5           | 1000          |
+-------------+---------------+

Result table:
+--------------+--------------+
| bin          | total        |
+--------------+--------------+
| [0-5>        | 3            |
| [5-10>       | 1            |
| [10-15>      | 0            |
| 15 or more   | 1            |
+--------------+--------------+

For session_id 1, 2 and 3 have a duration greater or equal than 0 minutes and less than 5 minutes.
For session_id 4 has a duration greater or equal than 5 minutes and less than 10 minutes.
There are no session with a duration greater or equial than 10 minutes and less than 15 minutes.
For session_id 5 has a duration greater or equal than 15 minutes.

IDEA:
Create a common table expression
The CREATE TABLE by UNION rows

cte: https://www.mysqltutorial.org/mysql-cte/

*/
WITH dura_cte AS(       
    SELECT (duration/60) AS mins
    FROM Sessions
)

SELECT '[0-5>' as bin, SUM(CASE WHEN mins < 5 AND mins >= 0 THEN 1 ELSE 0 END) AS total
FROM dura_cte
UNION ALL
SELECT '[5-10>' as bin, SUM(CASE WHEN mins < 10 AND mins >= 5 THEN 1 ELSE 0 END) AS total
FROM dura_cte
UNION ALL
SELECT '[10-15>' as bin, SUM(CASE WHEN mins < 15 AND mins >= 10 THEN 1 ELSE 0 END) AS total
FROM dura_cte
UNION ALL
SELECT '15 or more' as bin, SUM(CASE WHEN mins >= 15 THEN 1 ELSE 0 END) AS total
FROM dura_cte