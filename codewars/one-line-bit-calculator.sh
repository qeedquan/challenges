#!/bin/sh

cat << EOF >/dev/null

Complete the function which converts hex number (given as a string) to a decimal number.

EOF

calculate() {
	echo "ibase=2; $1 + $2" | bc
}

calculate '10' '11'
calculate '100' '10101'

