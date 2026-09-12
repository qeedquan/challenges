#!/bin/sh

cat << EOF >/dev/null

Complete the function that takes a non-negative integer n as input, and returns a list of all the powers of 2 with the exponent ranging from 0 to n (inclusive).

Examples
n = 0  ==> [1]        # [2^0]
n = 1  ==> [1, 2]     # [2^0, 2^1]
n = 2  ==> [1, 2, 4]  # [2^0, 2^1, 2^2]

EOF

powers_of_two() {
	r=""
	for i in $(seq 0 $1); do
		x=$(echo "2^$i" | bc)
		r="$r $x"
	done
	echo $r
}

powers_of_two 0
powers_of_two 1
powers_of_two 2
powers_of_two 64
