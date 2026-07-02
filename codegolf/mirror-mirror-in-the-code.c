/*

Two-dimensional programming languages often have mirror commands like / and \ to redirect the instruction pointer on the grid:

>>>>\
    v
    v
<<<</
In this challenge, you're given an incoming direction and a mirror and you need to determine the outgoing direction.

Rules
The incoming direction will be given as one of the characters NESW and the mirror will be given as either / or \. You may receive these in any order. You must use uppercase letters.

You may take input in any convenient format, including a two-character string, a string using some separator between the characters, a pair of characters in a list, or even a pair of singleton strings. If you do use a string with separator, the separator cannot use any of the characters NWSE\/.

Output should be a character from NESW or single-character string.

You may write a program or a function and use any of the our standard methods of receiving input and providing output.

You may use any programming language, but note that these loopholes are forbidden by default.

This is code-golf, so the shortest valid answer – measured in bytes – wins.

Test Cases
There are only 8 possible inputs you need to handle, so there is no excuse for not testing your code on all of them:

N /   -->   W
N \   -->   E
E /   -->   S
E \   -->   N
S /   -->   E
S \   -->   W
W /   -->   N
W \   -->   S

*/

#include <assert.h>

int
direction(int d, int m)
{
	static const char tab[] = " NESSWNW";

	return tab[(d + m) & 7];
}

int
main(void)
{
	assert(direction('N', '/') == 'W');
	assert(direction('N', '\\') == 'E');
	assert(direction('E', '/') == 'S');
	assert(direction('E', '\\') == 'N');
	assert(direction('S', '/') == 'E');
	assert(direction('S', '\\') == 'W');
	assert(direction('W', '/') == 'N');
	assert(direction('W', '\\') == 'S');

	return 0;
}
