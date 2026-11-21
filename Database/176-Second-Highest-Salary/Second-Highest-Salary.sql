# Write your MySQL query statement 
SELEcT (SELEcT  distinct e.salary as SecondHighestSalary 
from Employee as e ORDER BY salary DESC LIMIT 1 OFFSET 1) as SecondHighestSalary;