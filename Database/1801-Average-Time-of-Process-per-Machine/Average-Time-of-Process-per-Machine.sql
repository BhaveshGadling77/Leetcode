SELECT machine_id,
       ROUND(AVG(processing_time),3) as processing_time
FROM
(
    SELECT machine_id,
           process_id,
           SUM(
               CASE
                   WHEN activity_type='start' THEN -timestamp
                   ELSE timestamp
               END
           ) AS processing_time
    FROM Activity
    GROUP BY machine_id, process_id
) t
GROUP BY machine_id;