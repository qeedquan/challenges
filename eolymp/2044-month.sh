#!/bin/sh

cat << EOF >/dev/null

Given an integer n (1≤n≤12) representing the ordinal number of a month in the year, print the name of the corresponding month in English.

Input
The ordinal number of the month n.

Output
Print the name of the corresponding month in English.

Examples
Input #1
1

Answer #1
January

EOF

solve() {
	cal $1 | head -n 1 | awk '{ print $1 }'
}

for i in $(seq 1 12); do
	solve $i
done
