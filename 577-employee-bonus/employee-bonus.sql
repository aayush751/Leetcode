# Write your MySQL query statement below
select em.name , b.bonus
from Employee as em
left join Bonus as b
on em.empId = b.empId 
where b.bonus < 1000 or b.bonus is null;