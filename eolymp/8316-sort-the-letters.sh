#!/bin/sh

cat << EOF >/dev/null

A string consisting of lowercase Latin letters is given. Sort its letters in ascending and then in descending order according to their ASCII codes.

Input
The input contains one line with no more than 100 lowercase Latin letters (a–z).

Output
Print the input string's letters sorted in non-decreasing order of their ASCII codes on the first line, and in non-increasing order on the second line.

Examples
Input #1
qwerty

Answer #1
eqrtwy
ywtrqe

EOF

arrange() {
	echo $1 | grep -o . | sort $2 | tr -d '\n'
	echo
}

solve() {
	arrange $1
	arrange $1 -r
}

solve "qwerty"

