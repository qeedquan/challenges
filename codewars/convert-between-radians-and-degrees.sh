#!/bin/sh

cat << EOF >/dev/null

Extend the Math object (JS) or module (Ruby and Python) to convert degrees to radians and viceversa. The result should be rounded to two decimal points. Note that all methods of Math object are static.

Example:

Math.degrees(Math.PI) //180deg
Math.radians(180) //3.14rad

EOF

deg2rad() {
	echo "pi=4*a(1); $1*pi/180" | bc -l
}

rad2deg() {
	echo "pi=4*a(1); $1*180/pi" | bc -l
}

rad2deg 3.141592653589
deg2rad 180

