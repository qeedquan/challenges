/*

Given a letter of the English alphabet, your task is to build a semi-diagonal alphabet to the input.

How to build a Semi-Diagonal alphabet?
Brief Description: First, you take the position of the letter in the alphabet, P (P is 1-indexed here). Then, you print each letter until the input (inclusive) on a line, preceded by P-1 and repeat that letter P times, interleaving with spaces.

Examples:

Given F, your program should output:

A
 B B
  C C C
   D D D D
    E E E E E
     F F F F F F
Given K, your program should output:

A
 B B
  C C C
   D D D D
    E E E E E
     F F F F F F
      G G G G G G G
       H H H H H H H H
        I I I I I I I I I
         J J J J J J J J J J
          K K K K K K K K K K K
Given A, your program should output:

A
Rules
You may choose either lowercase or uppercase characters, but that should be consistent.

You may have extraneous spaces as follows:

One consistent leading space (on each line).
A trailing or leading newline(s).
Trailing spaces.
Input and output can be taken by any standard mean, and default loopholes apply.

You are allowed to output a list of lines instead, as long as you also provide the ascii-art version.

This is code-golf, so the shortest code in bytes wins!

Inspired by this challenge.
https://codegolf.stackexchange.com/questions/125117/diagonal-alphabet

*/

#include <stdio.h>

void
semidiag(int c)
{
	int i, j, n;

	n = 1;
	for (i = 'A'; i <= c; i++) {
		for (j = 1; j < n; j++)
			printf(" ");

		for (j = 0; j < n; j++) {
			printf("%c", i);
			if (j + 1 < n)
				printf(" ");
		}
		printf("\n");

		n += 1;
	}
	printf("\n");
}

int
main()
{
	semidiag('F');
	semidiag('K');
	semidiag('Z');

	return 0;
}
