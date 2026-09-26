#!/bin/sh

cat << EOF >/dev/null

Swap the first and last names in a string.

Input
The input file contains a single line with the last name and first name of a person, separated by exactly one space.

Output
Output the same information, but with the first name first and the last name second, also separated by exactly one space.

Examples
Input #1
Pupkin Vasily
Answer #1
Vasily Pupkin

EOF

solve() {
	echo $2 $1
}

solve "Pupkin" "Vasily"

