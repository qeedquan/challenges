#!/bin/sh

cat << EOF >/dev/null

You are given two interior angles (in degrees) of a triangle.

Write a function to return the 3rd.

Note: only positive integers will be tested.

https://en.wikipedia.org/wiki/Triangle

EOF

third_angle() {
	echo "180 - $1 - $2" | bc
}

third_angle 45 45
third_angle 30 60
third_angle 50 50

