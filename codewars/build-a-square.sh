#!/bin/sh

cat << EOF >/dev/null

I will give you an integer. Give me back a shape that is as long and wide as the integer. The integer will be a whole number between 1 and 50.

Example
n = 3, so I expect a 3x3 square back just like below as a string:

+++
+++
+++

EOF

square() {
	for i in $(seq 1 $1); do
		for j in $(seq 1 $1); do
			echo -n '+'
		done
		echo
	done
	echo
}

square 3
square 10

