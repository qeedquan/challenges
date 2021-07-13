/*

SQL Schema

Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

*/

-- cat second-highest-salary.sql | sqlite3 employee.db

.headers on

drop table if exists Employee;

create table Employee(
	Id int,
	Salary int
);

insert into Employee
	(Id, Salary)
values
	(1, 100),
	(2, 200),
	(3, 300);

select distinct
	Salary as SecondHighestSalary
from
	Employee
order by
	Salary desc
limit 1 offset 1;
