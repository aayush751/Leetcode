# Write your MySQL query statement below
SELECT Q1.person_name
FROM Queue AS Q1
INNER JOIN  Queue AS Q2
ON Q1.turn >= Q2.turn
GROUP BY Q1.turn
HAVING SUM(Q2.weight)  <= 1000
ORDER BY Q1.turn desc limit 1