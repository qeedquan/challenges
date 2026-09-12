#!/bin/sh

cat << EOF >/dev/null

Problem
Problem Statement
Write a program that accepts sets of three integers, and prints the maximum among the three.

Input
First line contains the number of triples, N.
The next N lines which follow each have three space separated integers.

Output
For each of the N triples, output one new line which contains the maximum integer among the three.

Constraints
1 ≤ N ≤ 20
1 ≤ every integer ≤ 1000000

Sample Input
3
1 2 3
10 5 1
100 999 500

Sample Output
3
10
999

EOF

max3() {
	echo $@ | tr ' ' '\n' | sort -n | tail -n 1
}

max3 1 2 3
max3 10 5 1
max3 100 999 500
