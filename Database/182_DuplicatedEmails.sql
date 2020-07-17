/*
https://leetcode.com/problems/duplicate-emails/

Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

要有一种分布解决的思维，先从一张表过渡到有所需信息的表，然后再取值

*/

-- Write your MySQL query statement below
SELECT Email 
FROM(
    SELECT Email, COUNT(Email) as Nums
    FROM Person
    GROUP BY Email
) AS EmailCount
WHERE Nums > 1;

-- Simple Way
SELECT Email
FROM Person
GROUP BY Email
HAVING COUNT(Email) > 1;

