#!/bin/sh

cat << EOF >/dev/null

The program takes a line of text as input. Your task is to output an exact duplicate of this input text.

Input
A single line containing only Latin letters, punctuation marks, and spaces.

Output
An exact copy of the input text.

Examples

Input #1
Hello, world!

Answer #1
Hello, world!

EOF

solve() {
	echo $@
}

solve "Hello, world!"
