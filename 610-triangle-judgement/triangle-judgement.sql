# Write your MySQL query statement below
SELECT x,
       y,
       z,
       CASE WHEN X+Y > Z AND Y+Z > X AND X+Z > Y THEN 'Yes' ELSE 'No' end AS triangle
FROM triangle ;