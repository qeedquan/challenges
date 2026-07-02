#!/bin/sh

cat << EOF >/dev/null

Bob is a lazy man.

He needs you to create a method that can determine how many letters (both uppercase and lowercase ASCII letters) and digits are in a given string.

Example:

"hel2!lo" --> 6

"wicked .. !" --> 6

"!?..A" --> 1

EOF

count() {
	echo $@ | tr -c -d ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 | wc -c
}

count "hel2!lo"
count "wicked .. !"
count "!?..A"

