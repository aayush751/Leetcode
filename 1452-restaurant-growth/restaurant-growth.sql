# Write your MySQL query statement below
SELECT visited_on ,
(
    SELECT SUM(amount)
    FROM customer
    WHERE visited_on BETWEEN date_sub(c.visited_on ,interval 6 day)
    AND c.visited_on
) AS amount ,
ROUND((
    SELECT SUM(amount)/7
    FROM customer
    WHERE visited_on BETWEEN date_sub(c.visited_on ,interval 6 day)
    AND c.visited_on
),2) AS average_amount
FROM customer AS c
WHERE visited_on >= (
    SELECT date_add(min(visited_on), interval 6 day)
    FROM customer
)
GROUP BY visited_on
ORDER BY visited_on