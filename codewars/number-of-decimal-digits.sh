#!/bin/sh

cat << EOF >/dev/null

Determine the total number of digits in the integer (n>=0) given as input to the function. For example, 9 is a single digit, 66 has 2 digits and 128685 has 6 digits. Be careful to avoid overflows/underflows.

All inputs will be valid.

EOF

initbc() {
	funcs=$(cat)
}

initbc << EOF

define floor(x) {
	auto os, xx;
	os = scale
	scale = 0
	xx = x/1
	if (xx > x)
		. = xx--
	scale = os
	return (xx)
}

EOF

digits() {
	echo "$funcs; floor(l($1)/l(10)) + 1" | bc -l
}

digits 66
digits 128685
