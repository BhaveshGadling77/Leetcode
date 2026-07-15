# Write your MySQL query statement below
SELECT w.id
FROM Weather w
JOIN Weather wt 
    ON DATEDIFF(w.recordDate, wt.recordDate) = 1
    WHERE w.temperature > wt.temperature;