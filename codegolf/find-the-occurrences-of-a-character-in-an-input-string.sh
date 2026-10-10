#!/bin/sh

cat << EOF >/dev/null

Challenge
Write a program that, given a string x which is 10 characters long and a character y, outputs the number of times character y occurs in string x.

The shortest program in bytes to do so wins.

Example
Input: tttggloyoi, t
Output: 3
Input: onomatopoe, o
Output: 4

EOF

count() {
	echo $1 | awk -F $2 '{print NF-1}'
}

count "tttggloyoi", "t"
count "onomatopoe", "o"
