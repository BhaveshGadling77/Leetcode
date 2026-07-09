# Write your MySQL query statement below
WITH tb AS(
    SELECT
        *, 
        CASE 
            WHEN operation='Buy' THEN -price
            ELSE price 
        END AS bs
    FROM Stocks
)

SELECT 
    stock_name,
    SUM(bs) AS capital_gain_loss
FROM tb
GROUP BY stock_name;