#!/bin/sh

cat << EOF >/dev/null

Write the function resistor_parallel that receive an undefined number of resistances parallel resistors and return the total resistance.

You can assume that there will be no 0 as parameter.
Also there will be at least 2 arguments.

Formula:
total = 1 / (1/r1 + 1/r2 + .. + 1/rn)

Examples:
resistor_parallel(20, 20) will return 10.0
resistor_parallel(20, 20, 40) will return 8.0

EOF

parallel() {
	s=""
	for i in $@; do
		s="$s+1/$i"
	done
	s=$(echo $s | sed 's/^.//')
	s="1/($s)"
	echo "scale=50; $s" | bc
}

parallel 20 20
parallel 20 20 40
parallel 3 4
parallel 1 2 3 4 5 6 7 8 9 10
parallel 1337
