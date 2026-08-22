#!/bin/sh

cat << EOF >/dev/null

Complete the function which converts hex number (given as a string) to a decimal number.

EOF

hex2dec() {
	in=$(echo $1 | tr 'a-z' 'A-Z')
	echo "ibase=16; $in" | bc
}

hex2dec 'FF'
hex2dec '80'
hex2dec 'ffff'
hex2dec '1337'
hex2dec '3f02'
