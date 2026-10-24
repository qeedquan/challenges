/*

Description

Boudreaux and Thibodeaux are on the road again . . .

"Boudreaux, we have to get this shipment of mudbugs to Baton Rouge by tonight!"

"Don't worry, Thibodeaux, I already checked ahead. There are three underpasses and our 18-wheeler will fit through all of them, so just keep that motor running!"

"We're not going to make it, I say!"

So, which is it: will there be a very messy accident on Interstate 10, or is Thibodeaux just letting the sound of his own wheels drive him crazy?

Input

Input to this problem will consist of a single data set. The data set will be formatted according to the following description.

The data set will consist of a single line containing 3 numbers, separated by single spaces. Each number represents the height of a single underpass in inches. Each number will be between 0 and 300 inclusive.

Output

There will be exactly one line of output. This line will be:

NO CRASH

if the height of the 18-wheeler is less than the height of each of the underpasses, or:
CRASH X

otherwise, where X is the height of the first underpass in the data set that the 18-wheeler is unable to go under (which means its height is less than or equal to the height of the 18-wheeler).
The height of the 18-wheeler is 168 inches.

Sample Input

180 160 170

Sample Output

CRASH 160

Source

South Central USA 2003

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
fate(int a, int b, int c, char *s)
{
	int h;

	h = 168;
	if (a <= h)
		sprintf(s, "CRASH %d", a);
	else if (b <= h)
		sprintf(s, "CRASH %d", b);
	else if (c <= h)
		sprintf(s, "CRASH %d", c);
	else
		sprintf(s, "NO CRASH");
	return s;
}

void
test(int a, int b, int c, const char *r)
{
	char s[128];

	fate(a, b, c, s);
	printf("%s\n", s);
	assert(!strcmp(s, r));
}

int
main(void)
{
	test(180, 160, 170, "CRASH 160");

	return 0;
}
