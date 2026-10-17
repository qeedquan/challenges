/*

Task
Given one non-whitespace printable character, make a 3x3 square representation of that input. For example, if the input is #, then the output is:

###
# #
###
Rules
The output format is strict, although a trailing newline is allowed. It means that the space in the middle is required, and also that the two newline characters separating the three lines are required.

Testcases
Input: #

Output:

###
# #
###

Input: A

Output:

AAA
A A
AAA

Input: 0

Output:

000
0 0
000

Scoring
This is code-golf. Shortest answer in bytes wins.

Leaderboard
Here is a Stack Snippet to generate both a regular leaderboard and an overview of winners by language.

Show code snippet

*/

#include <stdio.h>

void
square(char c)
{
	printf("%c%c%c\n", c, c, c);
	printf("%c %c\n", c, c);
	printf("%c%c%c\n\n", c, c, c);
}

int
main(void)
{
	square('#');
	square('A');
	square('0');

	return 0;
}
