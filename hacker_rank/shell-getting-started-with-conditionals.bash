#!/bin/bash

cat << EOF > /dev/null

Read in one character from STDIN.
If the character is 'Y' or 'y' display "YES".
If the character is 'N' or 'n' display "NO".
No other character will be provided as input.

Input Format

One character

Constraints

The character will be from the set {yYnN}.

Output Format

echo YES or NO to STDOUT.

Sample Input

y

Sample Output

YES

EOF

truth() {
	if [[ "$1" == "Y" || "$1" == "y" ]]; then
		echo "YES"
	elif [[ "$1" == "N" || "$1" == "n" ]]; then
		echo "NO"
	fi
}

truth y
truth Y
truth N
truth n
