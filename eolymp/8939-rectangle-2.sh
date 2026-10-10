#!/bin/sh

cat << EOF >/dev/null

Positive integer n is given. Print the rectangle of size 4×n from symbols # as shown in the sample.

Input
One positive integer n (n≤100).

Output
Print the rectangle of size 4×n from symbols #.

Examples

Input #1
2

Answer #1
##
##
##
##

EOF

solve() {
	for i in $(seq 1 4); do
		for j in $(seq 1 $1); do
			echo -n "#"
		done
		echo
	done
}

solve 2
