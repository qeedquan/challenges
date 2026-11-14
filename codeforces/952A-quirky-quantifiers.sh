#!/bin/sh

cat << EOF > /dev/null

Input
The input contains a single integer a (10 ≤ a ≤ 999).

Output
Output 0 or 1.

Examples
input
13
output
1

input
927
output
1

input
48
output
0

EOF

parity() {
	echo $(($1 & 1))
}

parity 13
parity 927
parity 48
