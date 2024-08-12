# Write your MySQL query statement below
SELECT p.product_name , SUM(o.unit) as unit
FROM Products AS p
LEFT JOIN Orders AS O
ON p.product_id = o.product_id
WHERE EXTRACT(year_month FROM o.order_date) = 202002
GROUP BY o.product_id
HAVING SUM(o.unit) >= 100