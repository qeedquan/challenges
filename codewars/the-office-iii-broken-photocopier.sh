#!/bin/sh

cat << EOF >/dev/null

The bloody photocopier is broken... Just as you were sneaking around the office to print off your favourite binary code!

Instead of copying the original, it reverses it: '1' becomes '0' and vice versa.

Given a string of binary, return the version the photocopier gives you as a string.

EOF

broken() {
	echo $@ | tr "10" "01"
}

broken "000"
broken "101"
broken "111"

