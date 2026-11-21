#!/bin/sh

cat << EOF >/dev/null

The program takes a single line of text as input, such as False. Your task is to output this text twice, each on a separate line.

Input
A single line of text containing only Latin letters.

Output
The answer to the task.

Examples

Input #1
False

Answer #1
False
False

EOF

solve() {
	echo $@
	echo $@
}

solve "False"
