#!/bin/sh

cat << EOF >/dev/null

The program takes a natural number n and a piece of text, such as Hello. Your task is to output this text repeated n times on a single line, with each repetition separated by a space.

Input
The first line contains a natural number n, and the second line contains a text consisting of Latin letters.

Output
The repeated text as specified.

Examples

Input #1
3
Hello

Answer #1
Hello Hello Hello

EOF

solve() {
	for i in $(seq 1 $1); do
		echo -n "$2 "
	done
	echo
}

solve 3 "Hello"
