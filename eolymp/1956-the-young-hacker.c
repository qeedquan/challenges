/*

Taras dreams of becoming a computer hacker. After watching various movies and browsing the Internet, he realized that mathematics is essential in this field as well.
Unfortunately, this means he must learn mathematics, which he does not like.
To start, he became interested in number systems, and since computer hackers often represent messages as sequences of hexadecimal digits,
he focused on the hexadecimal system.
He learned that, in addition to ordinary decimal digits, the hexadecimal system uses the digits A, B, C, D, E, and F.

Now Taras is interested in how to quickly find the remainder when any number given in hexadecimal notation is divided by 5.

Input
The input contains a single line with a number in hexadecimal notation. Since Taras is not yet in school, the number of digits is at least one and no more than 10^6.

Output
Output a single digit—the remainder when the given number is divided by 5.

Examples
Input #1
5F0

Answer #1
0

*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>

long
solve(const char *s)
{
	return strtol(s, NULL, 16) % 5;
}

int
main()
{
	assert(solve("5F0") == 0);
	return 0;
}
