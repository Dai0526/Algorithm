/*
https://leetcode.com/problems/number-of-comments-per-post/

Write an SQL query to find number of comments per each post.

Result table should contain post_id and its corresponding number_of_comments, and must be sorted by post_id in ascending order.

Submissions may contain duplicate comments. You should count the number of unique comments per post.

Submissions may contain duplicate posts. You should treat them as one post.

The query result format is in the following example:

Submissions table:
+---------+------------+
| sub_id  | parent_id  |
+---------+------------+
| 1       | Null       |
| 2       | Null       |
| 1       | Null       |
| 12      | Null       |
| 3       | 1          |
| 5       | 2          |
| 3       | 1          |
| 4       | 1          |
| 9       | 1          |
| 10      | 2          |
| 6       | 7          |
+---------+------------+

Result table:
+---------+--------------------+
| post_id | number_of_comments |
+---------+--------------------+
| 1       | 3                  |
| 2       | 2                  |
| 12      | 0                  |
+---------+--------------------+

The post with id 1 has three comments in the table with id 3, 4 and 9. The comment with id 3 is repeated in the table, we counted it only once.
The post with id 2 has two comments in the table with id 5 and 10.
The post with id 12 has no comments in the table.
The comment with id 6 is a comment on a deleted post with id 7 so we ignored it.


Get all post by

SELECT sub_id AS post_id
FROM Submissions
WHERE parent_id IS NULL
GROUP BY sub_id

Then JOIN with Submission to find count of sub_id
or
JOIN first
*/

SELECT s1.sub_id AS post_id, COUNT(DISTINCT s2.sub_id) AS number_of_comments
FROM Submissions s1 LEFT JOIN Submissions s2
ON s1.sub_id = s2.parent_id
WHERE s1.parent_id IS NULL
GROUP BY s1.sub_id