# Write your MySQL query statement below
SELECT  Department , Employee , Salary
FROM 
(select d.name AS Department , e.name AS Employee , e.Salary  AS Salary ,
DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.Salary DESC) AS ranks
from Employee AS e
LEFT JOIN Department AS d
ON e.departmentId = d.id) temp
WHERE ranks <= 3