# Write your MySQL query statement below
SELECT sell_date , COUNT(DISTINCT Product) AS num_sold,
GROUP_CONCAT(DISTINCT Product ORDER BY Product SEPARATOR ',') AS Products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date