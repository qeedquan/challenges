/*

SQL Schema

Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

Note: All emails are in lowercase.

*/

-- cat duplicate-emails.sql | sqlite3 person.db

.headers on

drop table if exists Person;

create table Person(
	Email varchar
);

insert into Person
	(Email)
values
	("a@b.com"),
	("c@d.com"),
	("a@b.com");

select Email
from
	Person
group by
	Email
having count(Email) > 1;
