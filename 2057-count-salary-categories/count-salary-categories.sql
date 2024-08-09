# Write your MySQL query statement below
SELECT "Low Salary" AS category ,
SUM(if(income < 20000, 1,0)) AS accounts_count
FROM accounts
UNION
SELECT "Average Salary" AS category ,
SUM(if(income BETWEEN 20000 AND 50000, 1,0)) AS accounts_count
FROM accounts
UNION
SELECT "High Salary" AS category ,
SUM(if(income > 50000, 1,0)) AS accounts_count
FROM accounts
