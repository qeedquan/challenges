/*

Description:
Task
Four men, a, b, c and d are standing in a line, one behind another.

There's a wall between the first three people (a, b and c) and the last one (d).

The men a, b and c are lined up in order of height, so that:

person a can see the backs of b and c
person b can see the back of c
person c can see just the wall
There are 4 hats, 2 black and 2 white. Each person is given a hat. None of them can see their own hat, but person a can see the hats of b and c, while person b can see the hat of person c. Neither c nor d can see any hats.

Once a person figures out the color of their hat, they shout it.

https://imgur.com/m6wvteb

Your task is to return the person who will guess their hat first. You can assume that they will speak only when they reach a correct conclusion.

Input/Output
[input] string a
a's hat color ("white" or "black").

[input] string b
b's hat color ("white" or "black").

[input] string c
c's hat color ("white" or "black").

[input] string d
d's hat color ("white" or "black").

[output] an integer
The person to guess his hat's color first, 1 for a, 2 for b, 3 for c and 4 for d.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

int
guesshatcolor(const char *, const char *b, const char *c, const char *)
{
	return (!strcmp(b, c)) ? 1 : 2;
}

int
main()
{
	assert(guesshatcolor("black", "white", "black", "white") == 2);
	assert(guesshatcolor("white", "black", "white", "black") == 2);
	assert(guesshatcolor("white", "black", "black", "white") == 1);
	return 0;
}
