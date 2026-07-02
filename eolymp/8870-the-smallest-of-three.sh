#!/bin/sh

cat << EOF >/dev/null

Three integers a,b and c are given. Print the smallest of them.

Input
Three integers a, b and c.

Output
Print the smallest of three given numbers.

Examples
Input #1
7 2 4

Answer #1
2

EOF

solve() {
	echo $@ | tr ' ' '\n' | sort | head -1
}

solve 7 2 4
