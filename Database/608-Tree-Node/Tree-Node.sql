# Write your MySQL query statement below
SELECT
    t1.id,
    CASE
        WHEN t1.p_id IS NULL THEN 'Root'
        WHEN t2.id IS NOT NULL THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree t1
LEFT JOIN Tree t2
    ON t1.id = t2.p_id
GROUP BY t1.id, t1.p_id;