#!/bin/sh

cat << EOF > /dev/null

You are given three integers a, b, and c. Determine if one of them is the sum of the other two.

Input
The first line contains a single integer t (1≤t≤9261) — the number of test cases.

The description of each test case consists of three integers a, b, c (0≤a,b,c≤20).

Output
For each test case, output "YES" if one of the numbers is the sum of the other two, and "NO" otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example

input
7
1 4 3
2 5 8
9 11 20
0 0 0
20 20 20
4 12 3
15 7 8

output
YES
NO
YES
YES
NO
NO
YES

Note
In the first test case, 1+3=4.

In the second test case, none of the numbers is the sum of the other two.

In the third test case, 9+11=20.

EOF

max() {
	if [ $1 -gt $2 ]; then
		echo $1
	else
		echo $2
	fi
}

min() {
	if [ $1 -lt $2 ]; then
		echo $1
	else
		echo $2
	fi
}

mid() {
	max $(min $1 $2) $(min $(max $1 $2) $3)
}

sumof() {
	a=$(min $(min $1 $2) $3)
	b=$(mid $1 $2 $3)
	c=$(max $(max $1 $2) $3)
	if [ $((a+b)) -eq $c ]; then
		echo "YES"
	else
		echo "NO"
	fi
}

sumof 1 4 3
sumof 2 5 8
sumof 9 11 20
sumof 0 0 0
sumof 20 20 20
sumof 4 12 3
sumof 15 7 8
