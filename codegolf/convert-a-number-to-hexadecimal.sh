#!/bin/sh

cat << EOF >/dev/null

Challenge
Here's a simple one.

Write a function or program when given a number in base 10 as input, it will return or print that number's value in Hexadecimal.

Examples
15 -> F
1000 -> 3E8
256 -> 100
Rules
No built-in Hexadecimal functions whatsoever
Letters may be lowercase or uppercase
You will only need to worry about non-negative integers, no negatives or pesky decimals
It should work with any arbitrarily large number up to language's default type's limit.
Newline not mandatory
As usual, this is code-golf, so shortest code measured in bytes wins!

EOF

dec2hex() {
	echo "obase=16; ibase=10; $1" | bc
}

dec2hex 15
dec2hex 1000
dec2hex 256
