#!/usr/bin/env pwsh

<#

Weirdo Incorporates have a weird way of grading their staffs by the number of days they were present in the office:

  0 -  13 : F
 14 - 170 : E
171 - 180 : D
181 - 294 : C
295 - 300 : B
301 - 365 : A

Note: The range is inclusive (i.e. 0-13 means 0 days and 13 days both will evaluate
as grade 'F').
Objective:
Write a program/function that outputs/returns the grade of an employee for the number of days [within inclusive range of 0-365] attended by the employee.

Rules:
You may take input as a string or a number but must output as a string/alphabet (You may choose either lower or upper-case.)
Standard loopholes apply.
This is code-golf, so the shortest program in bytes wins!
Test cases:
12  => F
15  => E
301 => A
181 => C

#>

function grade($days) {
	if (0 -le $days -and $days -le 13) {
		echo "F"
	} elseif (14 -le $days -and $days -le 170) {
		echo "E"
	} elseif (171 -le $days -and $days -le 180) {
		echo "D"
	} elseif (181 -le $days -and $days -le 294) {
		echo "C"
	} elseif (295 -le $days -and $days -le 300) {
		echo "B"
	} elseif (301 -le $days -and $days -le 365) {
		echo "A"
	} else {
		echo "?"
	}
}

grade 12
grade 15
grade 301
grade 181
grade 365
