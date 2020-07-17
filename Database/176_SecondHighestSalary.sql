/* 
https://leetcode.com/problems/second-highest-salary/
Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
Write your MySQL query statement below

*/

-- It has problem, if there is no second high, then it should show null, but it give empty
SELECT DISTINCT Salary AS SecondHighestSalary 
FROM Employee
ORDER BY Employee.Salary DESC
LIMIT 1
OFFSET 1

-- This is more intuitive, but not scalable such as find nth.
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM EMPLOYEE)