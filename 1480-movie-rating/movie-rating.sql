# Write your MySQL query statement below
(SELECT u.name AS results 
FROM users AS u
LEFT JOIN movierating AS mr
ON u.user_id = mr.user_id
GROUP BY u.user_id
ORDER BY COUNT(mr.user_id) DESC ,u.name
LIMIT 1)
UNION ALL
(SELECT m.title AS results 
FROM movies AS m
LEFT JOIN movierating AS mr
ON m.movie_id = mr.movie_id
WHERE extract(year_month FROM created_at) = 202002
GROUP BY m.movie_id
ORDER BY AVG(mr.rating) DESC ,m.title
LIMIT 1)