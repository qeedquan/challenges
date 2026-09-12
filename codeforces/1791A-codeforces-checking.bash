#!/bin/bash

cat << EOF > /dev/null

Given a lowercase Latin character (letter), check if it appears in the string codeforces.

Input
The first line of the input contains an integer t (1≤t≤26) — the number of test cases.

The only line of each test case contains a character c — a single lowercase Latin character (letter).

Output
For each test case, output "YES" (without quotes) if c satisfies the condition, and "NO" (without quotes) otherwise.

You can output the answer in any case (for example, the strings "yEs", "yes", "Yes" and "YES" will be recognized as a positive answer).

Example
input
10
a
b
c
d
e
f
g
h
i
j

output
NO
NO
YES
YES
YES
YES
NO
NO
NO
NO

EOF

in_codeforces() {
	if [[ "codeforces" == *"$1"* ]]; then
		echo "YES"
	else
		echo "NO"
	fi
}

in_codeforces 'a'
in_codeforces 'b'
in_codeforces 'c'
in_codeforces 'd'
in_codeforces 'e'
in_codeforces 'f'
in_codeforces 'g'
in_codeforces 'h'
in_codeforces 'i'
in_codeforces 'j'
