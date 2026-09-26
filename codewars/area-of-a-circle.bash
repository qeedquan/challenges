#!/bin/bash

cat << EOF >/dev/null

Complete the function which will return the area of a circle with the given radius.

Returned value is expected to be accurate up to tolerance of 0.01.

If the radius is not positive, throw Error.

Example:

circleArea(43.2673);     // returns 5881.248  (± 0.01)
circleArea(68);          // returns 14526.724 (± 0.01)
circleArea(0);           // throws Error
circleArea(-1);          // throws Error

EOF

area() {
	if [[ "$1" == *"-"* ]] || [[ "$1" == "0" ]]; then
		echo false
		return
	fi

	echo "r=$1; r*r*4*a(1)" | bc -l
}

area -1485.86
area 0
area 43.2673
area 68
area 3

