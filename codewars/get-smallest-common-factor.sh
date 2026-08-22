#!/bin/sh

cat << EOF >/dev/null

Given an array of integers, return the smallest common factors of all integers in the array.

When i say Smallest Common Factor i mean the smallest number above 1 that can divide all numbers in the array without a remainder.

scf([200, 30, 18, 8, 64, 34]) //=> 2
scf([21, 45, 51, 27, 33]) //=> 3
scf([133, 147, 427, 266]) //=> 7

If there are no common factors above 1, return 1 (technically 1 is always a common factor).

EOF

initbc() {
	funcs=$(cat)
}

initbc << EOF

define gcd(a, b) {
	scale = 0
	while (b != 0) {
		t = b
		b = a % b
		a = t
	}
	return a
}

EOF

scf() {
	r=$1
	for x in $@; do
		r=$(echo "$funcs; gcd($r, $x)" | bc -l)
	done
	echo $r
}

scf 200 30 18 8 64 34
scf 21 45 51 27 33
scf 133 147 427 266

