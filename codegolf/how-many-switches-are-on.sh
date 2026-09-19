#!/bin/sh

cat << EOF >/dev/null

A class has N student and the class room has N switches (all turned OFF and numbered 1 to N). Each student has an enrollment number assigned from 1 to N. Each student serially (by number) toggles the switches that has a number which is divisible by his/her enrollment number.

Example: Student 1 will turn all the switches ON. Student 2 will turn all even switches OFF. Student N just toggles the Nth switch.

Write a function that takes N as input as returns number of ON switches. sample I/O

Input: 10
Output:3
No upper bound for N is given, but greater the scope, better the code. Shortest and innovative function wins

EOF

on() {
	echo "sqrt($1)" | bc
}

on 10
