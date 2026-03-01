#!/bin/sh

cat << EOF >/dev/null

Implement a function that returns the minimal and the maximal value of a list (in this order).

EOF

minmax() {
	min=$(echo $@ | sed 's/ /\n/g' | sort -h | head -n 1)
	max=$(echo $@ | sed 's/ /\n/g' | sort -h | tail -n 1)
	echo $min $max
}

minmax 5 3 2 10
minmax 13 100 21
minmax 294 8600 23 3 1 -3
