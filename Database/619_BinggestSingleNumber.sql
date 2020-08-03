/*
https://leetcode.com/problems/biggest-single-number/
Can you write a SQL query to find the biggest number, which only appears once.

+---+
|num|
+---+
| 8 |
| 8 |
| 3 |
| 3 |
| 1 |
| 4 |
| 5 |
| 6 | 
For the sample data above, your query should return the following result:
+---+
|num|
+---+
| 6 |
Note:
If there is no such number, just output null.
*/

SELECT IF(count(*) = 1, num, NULL) AS num
FROM my_numbers
GROUP BY num
ORDER BY num DESC 
LIMIT 1
