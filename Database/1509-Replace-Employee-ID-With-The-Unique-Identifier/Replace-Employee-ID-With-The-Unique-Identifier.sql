# Write your MySQL query statement below
SELECT emp.unique_id, emps.name FROM  Employees emps LEFT JOIN EmployeeUNI AS emp 
    ON emps.id=emp.id;