#!/bin/sh

cat << EOF >/dev/null

You are given an odd-length array of integers, in which all of them are the same, except for one single number.

Complete the method which accepts such an array, and returns that single different number.

The input array will always be valid! (odd-length >= 3)

Examples
[1, 1, 2] ==> 2
[17, 17, 3, 17, 17, 17, 17] ==> 3

EOF

stray() {
	echo "$@" | sed 's/ /\n/g' | uniq -u
}

stray 1 1 2
stray 17 17 3 17 17 17 17

