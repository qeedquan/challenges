/*

You would like to get the 'weight' of a name by getting the sum of the ascii values. However you believe that capital letters should be worth more than mere lowercase letters. Spaces, numbers, or any other character are worth 0.

Normally in ascii

a has a value of 97
A has a value of 65
' ' has a value of 32
0 has a value of 48

To find who has the 'weightier' name you will switch all the values so:

A will be 97
a will be 65
' ' will be 0
0 will be 0
etc...

For example Joe will have a weight of 254, instead of 286 using normal ascii values.

*/

#include <assert.h>
#include <stdio.h>

int
weight(const char *s)
{
	size_t i;
	int c, r;

	r = 0;
	for (i = 0; (c = s[i]); i++) {
		if ('A' <= c && c <= 'Z')
			r += 'a' + c - 'A';
		else if ('a' <= c && c <= 'z')
			r += 'A' + c - 'a';
	}
	return r;
}

int
main()
{
	assert(weight("Joe") == 254);
	assert(weight("CJ") == 205);
	assert(weight("cj") == 141);

	assert(weight("George Washington") == 1275);
	assert(weight("Billy Bob Joe") == 909);
	assert(weight("King George II") == 1012);

	assert(weight("r2d2") == 150);
	assert(weight("R2D2") == 214);
	assert(weight("C3PO") == 322);

	return 0;
}
