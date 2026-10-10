#!/bin/sh

cat << EOF >/dev/null

Write a program uses run-length encoding to shorten a list of non-negative integers it has to read in.

You can assume the non-negative integers can fit in 32bit signed integers.

Input Format

The length, n, of the list on the first line.

On the second line, a space-separated list of integers representing the list of integers.

Output Format

A space separated list of integers. The first 2 integers represent the first run, the next 2 integers the second run and so on. For each pair of integers representing a run, the first integer represents the length of the run and the second represents the value of the integer in the run.

Sample Input
1.
5
1 1 3 2 2

2.
3
1 1 1

Sample Output
1.
2 1 1 3 2 2

2.
3 1

Limits
0<n<10000

EOF

cat << EOF >/dev/null

@Arnaud Le Blanc

xargs -n1 reads the reast and outputs each number on one line:
1
1
3
2
2

uniq -c filters adjacent matching lines (with the c switch it also prints the number of adjancent lines) :
2 1
1 3
2 2

echo sees those numbers as separate arguments and just prints them separated by a space:

2 1 1 3 2 2

EOF

rle() {
	echo $@ | echo $(xargs -n1 | uniq -c)
}

rle 1 1 3 2 2
rle 1 1 1
