#!/bin/sh

cat << EOF > /dev/null

Challenge
Given two strings, work out if they both have exactly the same characters in them.

Example
Input

word, wrdo

This returns true because they are the same but just scrambled.

Input

word, wwro

This returns false.

Input

boat, toba

This returns true

Rules
Here are the rules!

Assume input will be at least 1 char long, and no longer than 8 chars.
No special characters, only a–z
All inputs can be assumed to be lowercase

Test Cases
boat, boat = true
toab, boat = true
oabt, toab = true
a, aa = false
zzz, zzzzzzzz = false
zyyyzzzz, yyzzzzzy = true
sleepy, pyels = false
p,p = true

EOF

strsort() {
	echo $1 | grep -o . | sort | tr -d '\n'
}

anagram() {
	a=$(strsort $1)
	b=$(strsort $2)
	if [ "$a" = "$b" ]; then
		echo "true"
	else
		echo "false"
	fi
}

anagram "boat" "boat"
anagram "toab" "boat"
anagram "oabt" "toab"
anagram "a" "aa"
anagram "zzz" "zzzzzzzz"
anagram "zyyyzzzz" "yyzzzzzy"
anagram "sleepy" "pyels"
anagram "p" "p"
