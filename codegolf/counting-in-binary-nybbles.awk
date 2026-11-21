#!/bin/awk -f

# This challenge is to output to your terminal, window, canvas or screen the numbers zero to 10 inclusive. Each outputted number must be shown as a 4-bit wide nybble, so zero must show as 0000 and so on.
#
# You may separate each number outputted with a space, comma or carriage return. Smallest solution wins but the numbers can be displayed in any order you like as long as there are no repeating numbers in your sequence.
#
# Entries in low-level binary languages need not worry about the comma or white space separators if it is not possible to output with commas or white spaces (i.e., the standard output is limited to binary only, or your solution is for an early computer kit such as the KIM-1 which has a limited digital display).

function dec2bin(n) {
	if (n == 0)
		return 0;

	b = "";
	while (n) {
		b = n%2b;
		n = int(n/2);
	}
	return int(b);
}

BEGIN {
	for (i = 0; i <= 10; i++) {
		printf "%04d\n", dec2bin(i);
	}
}
