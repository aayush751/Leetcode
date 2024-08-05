# Write your MySQL query statement below
select p.project_id ,round(avg(em.experience_years) , 2) as average_years
from Project as p
left join Employee as em 
on p.employee_id = em.employee_id 
group by p.project_id