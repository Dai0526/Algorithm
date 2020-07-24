/*
Write an SQL query to find the id and the name of all students who are enrolled in departments 
that no longer exists.

Return the result table in any order.
The query result format is in the following example:

Departments table:
+------+--------------------------+
| id   | name                     |
+------+--------------------------+
| 1    | Electrical Engineering   |
| 7    | Computer Engineering     |
| 13   | Bussiness Administration |
+------+--------------------------+

Students table:
+------+----------+---------------+
| id   | name     | department_id |
+------+----------+---------------+
| 23   | Alice    | 1             |
| 1    | Bob      | 7             |
| 5    | Jennifer | 13            |
| 2    | John     | 14            |
| 4    | Jasmine  | 77            |
| 3    | Steve    | 74            |
| 6    | Luis     | 1             |
| 8    | Jonathan | 7             |
| 7    | Daiana   | 33            |
| 11   | Madelynn | 1             |
+------+----------+---------------+

Result table:
+------+----------+
| id   | name     |
+------+----------+
| 2    | John     |
| 7    | Daiana   |
| 4    | Jasmine  |
| 3    | Steve    |
+------+----------+

John, Daiana, Steve and Jasmine are enrolled in departments 14, 33, 74 and 77 respectively.
department 14, 33, 74 and 77 doesn't exist in the Departments table.


*/

SELECT Students.id, Students.name
FROM Departments RIGHT JOIN Students
ON Departments.id = Students.department_id
WHERE Departments.name IS NULL;


SELECT id, name
FROM Students
WHERE department_id NOT IN (SELECT id FROM Departments);
