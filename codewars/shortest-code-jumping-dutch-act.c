/*

Shortest Code : Jumping Dutch act
(Code length limit: 90 chars)

This is the challenge version of coding 3min series. If you feel difficult, please complete the simple version ( http://www.codewars.com/kata/570bcd9715944a2c8e000009 )

Task:
Mr. despair wants to jump off Dutch act, So he came to the top of a building.

Scientific research shows that a man jumped from the top of the roof, when the floor more than 6, the person will often die in an instant; When the floor is less than or equal to 6, the person will not immediately die, he would scream. (without proof)

Input: floor, The height of the building (floor)

Output: a string, The voice of despair(When jumping Dutch act)

Example:
sc(2) should return "Aa~ Pa! Aa!"

It means:

Mr. despair jumped from the 2 floor, the voice is "Aa~"
He fell on the ground, the voice is "Pa!"
He did not die immediately, and the final voice was "Aa!"

sc(6) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Pa! Aa!"

sc(7) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!"

sc(10) should return "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!"

if floor<=1, Mr. despair is safe, return ""

Code length calculation
In javascript, we can't get the user's real code, we can only get the system compiled code. Code length calculation is based the compiled code.

For example:

If you typed sc=x=>x+1
after compile, it will be:sc=function(x){return x+1;}

The final advice
Just play in this kata, Don't experiment in real life ;-)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
sc(int n, char *b)
{
	char *p;
	int i;

	if (n < 2) {
		*b = '\0';
		return b;
	}

	p = b;
	for (i = 1; i < n; i++)
		p += sprintf(p, "Aa~ ");
	p += sprintf(p, "Pa!");
	if (n < 7)
		p += sprintf(p, " Aa!");
	return b;
}

void
test(int n, const char *r)
{
	char b[64];

	sc(n, b);
	printf("%d: %s\n", n, b);
	assert(!strcmp(b, r));
}

int
main()
{
	test(1, "");
	test(2, "Aa~ Pa! Aa!");
	test(6, "Aa~ Aa~ Aa~ Aa~ Aa~ Pa! Aa!");
	test(7, "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!");
	test(10, "Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Aa~ Pa!");

	return 0;
}
