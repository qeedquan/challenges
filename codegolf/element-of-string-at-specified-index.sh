#!/bin/sh

cat << EOF > /dev/null

Given a string s and a non-negative number n less than the length of s, output the character at the n-th position of s.

0-indexing and 1-indexing are allowed. For 1-indexing, n will be positive and less than or equal to the length of s.

s will consist of printable characters only.

Any reasonable input/output is permitted. Standard loopholes apply.

Testcases (0-indexing):

n s        output
0 "abcde"  a
1 "abcde"  b
2 "a != b" !
3 "+-*/"   /
4 "314159" 5
Testcases (1-indexing):

n s        output
1 "abcde"  a
2 "abcde"  b
3 "a != b" !
4 "+-*/"   /
5 "314159" 5
This is code-golf, so shortest answer in bytes wins.

EOF

# https://unix.stackexchange.com/questions/9468/how-to-get-the-char-at-a-given-position-of-a-string-in-shell-script
charat() {
	echo "$1" | sed 's/^.\{'$2'\}\(.\).*$/\1/'
}

charat "abcde" 0
charat "abcde" 1
charat "a != b" 2
charat "+-*/" 3
charat "314159" 4
