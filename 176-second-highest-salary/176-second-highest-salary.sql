# Write your MySQL query statement below 
select max(salary) as SecondHighestSalary from employee WHERE SALARY < (SELECT MAX(SALARY) FROM Employee)