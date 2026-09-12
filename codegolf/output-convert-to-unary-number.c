/*

Your task is it to output a number as a unary string. You get the number of a non-negative integer input in the range of 0 - 2'000'000'000.

Rules

You can choose any character for the digit you like. But it has to be the same everywhere and for every input.
Output a unary string by outputting this character N times. N is the input.
Input range is 0 - 2'000'000'000 (inclusive)
A input of 0 result in a empty string except the optional starting and ending characters.
You may or may not add optional starting and ending characters at the start and/or end, for example a newline character or [ and ]. If you do, all outputs (including of the input 0) must have one. This characters are different the the character for the digit you have chosen.
Input integer is given as decimal, hexadecimal, octal or binary number, whatever is convenient for you.
You are free to use a pattern of multiple characters for a single digit. But it has to be the same pattern for all digits and for every input.
Digit grouping is optional. If you use it, the group size has to be constant and the separation character has to be the same everywhere.
Your program should finish in less than 4h on a modern desktop CPU with 4 GB of free RAM, for any valid input.
Output is a string or stream of characters.
Examples / test cases:

Input  ->  Output

./yourProgram 1  -> 1
./yourProgram 12 -> 111111111111
./yourProgram 0  ->
./yourProgram 2000000000 | tr -d -c '1' | wc -c -> 2000000000
./yourProgram 32 -> 11111111111111111111111111111111
Non-golf example program:

#!/usr/bin/env python3
import sys

for i in range( int(sys.argv[1]) ):
  print("1", end='')
This is code-golf, so the shortest code wins.

Related but they have significant differences:

Output a random unary string
Parse a list of signed unary numbers
Brainf**k to Unary and Back

*/

#include <stdio.h>
#include <stdlib.h>

void
usage(void)
{
	fprintf(stderr, "usage: <number>\n");
	exit(2);
}

int
main(int argc, char *argv[])
{
	int i, n;

	if (argc < 2)
		usage();

	n = atoi(argv[1]);
	for (i = 0; i < n; i++)
		printf("1");

	return 0;
}
