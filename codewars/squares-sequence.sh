#!/bin/sh

cat << EOF >/dev/null

Complete the function that returns an array of length n, starting with the given number x and the squares of the previous number. If n is negative or zero, return an empty array/list.

Examples
2, 5  -->  [2, 4, 16, 256, 65536]
3, 3  -->  [3, 9, 81]

EOF

squares() {
	x=$1
	for i in $(seq 1 $2); do
		echo -n "$x "
		x=$(echo "$x^2" | bc)
	done
	echo
}

squares 2 5
squares 3 3
