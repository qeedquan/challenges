#!/bin/sh

cat << EOF >/dev/null

The program takes a single line of text as input, such as Linux. Your task is to output the message Welcome, Linux!

Input
A single line of text containing only Latin letters.

Output
The solution to the problem.

Examples

Input #1
Linux

Answer #1
Welcome, Linux!

EOF

solve() {
	echo "Welcome, $@!"
}

solve "Linux"
