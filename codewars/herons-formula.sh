#!/bin/sh

cat << EOF >/dev/null

Write function heron which calculates the area of a triangle with sides a, b, and c (x, y, z in COBOL).

Heron's formula:

sqrt(s * (s - a) * (s - b) * (s - c))

where

s = (a + b + c) / 2

Output should have 2 digits precision.

EOF

heron() {
	echo "scale=2; s=0.5*($1+$2+$3); sqrt(s*(s-$1)*(s-$2)*(s-$3))" | bc
}

heron 4 13 15
heron 14 14 10
