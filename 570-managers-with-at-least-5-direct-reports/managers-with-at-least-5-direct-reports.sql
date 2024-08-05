# Write your MySQL query statement below
select em.name
from employee as em
inner join employee as emp
on em.id = emp.managerid
group by emp.managerid
having count(emp.managerid) >=5