# Write your MySQL query statement below
select st.student_id , st.student_name , sub.subject_name , count(ex.subject_name) as attended_exams
from students as st
cross join subjects as sub
left join Examinations as ex
on st.student_id = ex.student_id and ex.subject_name = sub.subject_name 
group  by st.student_id , st.student_name , sub.subject_name 
order by st.student_id , st.student_name
