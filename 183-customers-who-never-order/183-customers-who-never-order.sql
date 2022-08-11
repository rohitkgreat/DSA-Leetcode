# Write your MySQL query statement below

SELECT A.name as Customers from Customers A
LEFT JOIN Orders B on  a.Id = B.customerid
WHERE b.CustomerId is NULL