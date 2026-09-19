/*

You are to write a program that, when given an integer between 1 and 5 (or 0 and 4 if you wish to use 0-indexing), outputs one of Code, Golf, and, Coding or Challenges. Each input can map to any of the five outputs. However, the mapping must be one to one (each input goes to a different output) and consistent when running the program multiple times.

For example, 1 -> Coding, 2 -> Golf, 3 -> and, 4 -> Code and 5 -> Challenges is a perfectly acceptable mapping. The capitalisation and spelling of the outputs must match, but leading and trailing whitespace is perfectly acceptable.

Rather than code-golf, we will use a different scoring system (lets use abcdef as an example program):

If your program works whenever any single (1) character is removed, your score is 1.
So bcdef, acdef, abdef, abcef, abcdf and abcde should all work as program on their own
By "work", I mean that the program still fulfils the first two paragraphs of this challenge spec.
The 5 possible inputs may be different to the unaltered program, and to each of the other altered programs, so long as they meet the rules above.
If your program still works whenever any pair (2) of consecutive characters are removed, your score is 2
So, to qualify for a score of 2, abcd, abcf, abef, adef and cdef must all work according to the challenge spec
And so on. If your program still works whenever any subset of length n of consecutive characters is removed from it, your score is n.
The program with the largest n wins. In order to compete, all programs must have a score of at least 1.
Your program must work for all i≤n in order to qualify for a score of n. So in order to score 5, your program must also score 1,2,3 and 4.

This is a Python program which will output all the possible alterations to your original program, along with the score they're worth.

*/

#include <stdio.h>
#include <stdlib.h>

const char *
statement(int n)
{
	switch (n) {
	case 1:
		return "Coding";
	case 2:
		return "Golf";
	case 3:
		return "and";
	case 4:
		return "Code";
	case 5:
		return "Challenges";
	}
	return "Botch";
}

int
main(int argc, char *argv[])
{
	if (argc >= 2) {
		printf("%s\n", statement(atoi(argv[1])));
	}

	return 0;
}
