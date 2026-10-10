#!/bin/bash

cat << EOF >/dev/null

Description
Numbers can be written in many kind of bases.

Normally we use base 10, wich is the decimal notation, for our numbers. In modern computerscience we use base 16 (hexadecimal) a lot, and beneath that we have base 2 (binary).

Given a number you can't tell what base it is, but you can tell what base it isn't from. E.g.: 1 exists in all bases, but 2 does not exist in base 2. It does exist in base 3 and so on.

Formal Inputs & Outputs
You will be given a number and you have to print the smallest base possible to wich it can belong and it's equivalent in base 10

Input description
The numbers to test

1
21
ab3
ff
Output description
The smallest base it belongs to plus the value in base 10

base 2 => 1
base 3 => 7
base 12 => 1575
base 16 => 255
Notes/Hints
For more info on numeral systems, you can start here wiki

For those new with bases. The letters translate to a higher value then 9, and because 10 exists out of 2 digits, they replace it with a letter.

This is the translation you need for this challenge

Digit	Value
a	10
b	11
c	12
d	13
e	14
f	15
Bonus
Print out all the decimal values for every base starting from the minimum till base 16.

Input
21
Output
base 3 => 7
base 4 => 9
base 5 => 11
base 6 => 13
base 7 => 15
base 8 => 17
base 9 => 19
base 10 => 21
base 11 => 23
base 12 => 25
base 13 => 27
base 14 => 29
base 15 => 31
base 16 => 33
Bonus inputs:
1
21
ab3
ff
Bonus 2
Make sure your program handles 0.

The minimum base for 0 is base 1 and it's value 0. As you might expect...

Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

EOF

# ported from @skeeto solution
solve() {
	number=$1
	base=0
	for c in $(echo "${number^^}" | grep -o .); do
		i=$(expr index 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $c)
		if ((i > base)); then
			base=$i
		fi
	done

	expr10="$base#$number"
	echo "base $base => $((expr10))"
}

solve 1
solve 21
solve ab3
solve ff

