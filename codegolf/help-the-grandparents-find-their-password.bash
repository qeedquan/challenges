#!/bin/bash

cat << EOF > /dev/null

Here's a scenario: A grandmother and grandfather forget what their GMail password is. They know the word, but can't remember which letters are capitals. The challenge is to take a word given and print(stdout) every combination of capital letters possible, essentially "brute-forcing" but only on a given string.

Example:
and would output

and
anD
aNd
aND
And
AnD
ANd
AND
Example:
ea! would output

ea!
Ea!
EA!
eA!
Rules
ASCII characters only
Input doesn't have to be lowercase
The order is not important
Non-alphabetic chars are left alone
Standard Loopholes apply.
Any form of input is allowed
Repetition is NOT allowed

EOF

cat << EOF > /dev/null

@Digital Trauma

The sed expression replaces every letter with {<LOWER>,<UPPER>}, where <LOWER> and <UPPER> are respectively the lower- and upper- case versions of that letter.
These are bash brace expansions which are then expanded - the eval ensures this is the last expansion to happen.

EOF

rem() {
	echo $1 | eval echo $(sed 's/[a-z]/{\l&,\u&}/gi')
}

rem "and"
rem "ea!"
rem "1234"
rem "wave"
