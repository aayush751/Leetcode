# Write your MySQL query statement below
DELETE p1
FROM Person AS P1
INNER JOIN person AS P2
ON p1.email = p2.email
 AND p1.id > p2.id