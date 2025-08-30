/*

Challenge
In this challenge you have to take a number as input and output the corresponding letter of the alphabet, and vice versa. (1 <=> A, 2 <=> B) etc.

1 -> A
2 -> B
...
26 -> Z

A -> 1
B -> 2
...
Z -> 26

Rules
This is code-golf, so shortest code in bytes wins.
The input will only consist of either an uppercase letter from A to Z or an integer from 1 to 26 inclusive.
Trailing whitespaces (space and newline) are allowed.

*/

#include <assert.h>

int
map(int c)
{
	if ('A' <= c && c <= 'Z')
		return c - 'A' + 1;
	if (1 <= c && c <= 26)
		return c + 'A' - 1;
	return c;
}

int
main()
{
	assert(map(1) == 'A');
	assert(map(2) == 'B');
	assert(map(26) == 'Z');

	assert(map('A') == 1);
	assert(map('B') == 2);
	assert(map('Z') == 26);

	return 0;
}
