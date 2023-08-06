# Write your MySQL query statement below
select max(num) as num from (select num,count(num) as a from MyNumbers group by num) t where a=1;