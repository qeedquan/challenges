#!/bin/sh

cat << EOF >/dev/null

Given a non-negative integer, return an array / a list of the individual digits in order.

Examples:

123 => [1,2,3]

1 => [1]

8675309 => [8,6,7,5,3,0,9]

EOF

digitize() {
	digits=$(echo $@ | sed 's/./&,/g' | sed 's/,$//')
	echo "[$digits]"
}

digitize 123
digitize 1
digitize 8675309
