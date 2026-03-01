#!/bin/sh

cat << EOF >/dev/null

What is the shortest way of generating a random string with a given length and with only alphanumeric characters allowed?

example of a random string: with N = 9 output would be aZua7I0Lk
the given length N can be assumed to be always greater than 0
if necessary you can assume 256 as a maximum value for N, but solutions with higher limits for N and still having a fast computation time are preferred
allowed characters: 0-9, a-z and A-Z
a character can occur more than once in the output string
each possible string should be equally likely (to the accuracy of your language's random number generator)

EOF

gen() {
	tr -dc a-zA-Z0-9 </dev/urandom | head -c $1
	echo
}

gen $1
