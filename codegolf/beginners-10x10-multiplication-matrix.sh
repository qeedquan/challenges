#!/bin/sh

cat << EOF >/dev/null

I was looking for a very easy task to look how short of a code can be produced on a beginners exercise.

The goal is to produce a simple table that looks like this common java/c# code is about 4 lines. So get your golfing-languages ready ;) Try to align the matrix in any way it is readable.

1 2 3    .. 10

2 4 6    .. 20

3 6 9    .. 30

. . .    .. .

10 20 30 .. 100
EDIT: The first answer below shows a propper alignment and solution

EOF

table() {
	n=$1
	for i in $(seq 1 $n); do
		for j in $(seq 1 $n); do
			x=$(echo $i*$j | bc)
			printf "%4d" $x
		done
		echo
	done
}

table 10

