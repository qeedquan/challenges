#!/bin/sh

cat << EOF > /dev/null

Inspired by a task for Programming 101, here's a challenge that hopefully isn't too easy (or a duplicate).

Input:
A positive integer n >= 1.
Output:
n lines of asterisks, where every new line has one asterisk more than the line before, and starting with one asterisk in the first line.

Test case (n=5):
    *
    **
    ***
    ****
    *****
This is code-golf, so shortest answer in bytes wins.

EOF

triangle() {
	for i in $(seq $1)
	do
		printf "%$((i))s\n" | tr " " "*"
	done
}

triangle 5
triangle 50
