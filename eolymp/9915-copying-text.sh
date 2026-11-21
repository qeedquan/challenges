#!/bin/sh

cat << EOF >/dev/null

The program takes a single line of text as input, such as Realy. Your task is to repeat this text four times on one line, with each repetition separated by a space.

Input
A single line of text containing only Latin letters.

Output
The answer to the problem.

Examples

Input #1
Realy

Answer #1
Realy Realy Realy Realy

EOF

solve() {
	echo $@ $@ $@ $@
}

solve "Realy"
