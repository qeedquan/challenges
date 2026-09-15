/*

You are given a letter c of the English alphabet ('A' < c < 'Z') which may be uppercase or lowercase.

Input
A single letter c of the English alphabet ('A' < c < 'Z') or ('a' < c < 'z').

Output
Print the letter that precedes c, followed by the letter that comes after c in the English alphabet, preserving the case.

Examples
Input #1
D

Answer #1
C E

Input #2
x

Answer #2
w y

*/

#include <stdio.h>

void
solve(int c)
{
	printf("%c %c\n", c - 1, c + 1);
}

int
main()
{
	solve('D');
	solve('x');

	return 0;
}
