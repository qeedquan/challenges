#!/bin/bash

cat << EOF >/dev/null

Your program will be given a number as input. Your challenge is to output all the numbers between 2 and 100 inclusive that are co-prime to the given number. (Two numbers are co-prime if their GCD is 1.) If no numbers between 2 and 100 are co-prime to the given number, the program shall not output anything.

The program must receive the number from STDIN, and the output must be a list of numbers separated by a comma and a space.

Contest closes June 14th, 2014, two weeks from now. The shortest solution wins.

Examples (here the range is from 2 to 20):

3:

2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20
12:

5, 7, 11, 13, 17, 19
9699690:

(No output: no numbers between 2 and 20 are co-prime to 9699690).

EDIT: Esoteric languages (e.g. J or GolfScript) are now being assessed separately from non-esoteric languages. This is to make the challenge fair.

EOF

gcd() (
	if (( $1 % $2 == 0)); then
		echo $2
	else
		gcd $2 $(( $1 % $2 ))
	fi
)

coprimes() {
	echo -n "$1: "
	for i in $(seq 2 100); do
		if [[ $(gcd $1 $i) == 1 ]]; then
			echo -n "$i "
		fi
	done
	echo
}

coprimes 3
coprimes 12

