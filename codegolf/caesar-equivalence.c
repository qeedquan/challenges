/*

Two strings are "Caesar equivalent" if the distance (counting up) between the corresponding characters are the same. Yes, I made this term up. Here's an example:

"Abc" and "Cde" are equivalent because

distance from a-c == 2
distance from b-d == 2
distance from c-e == 2
The capitalization doesn't make any difference.

"Hello" and "World" are not Caesar equivalent because

distance from h-w == 15
distance from e-o == 10
distance from l-r == 6
distance from l-l == 0
distance from o-d == 15
"Abcd" and "Yzab" are Caesar equivalent because

distance from a-y = 24
distance from b-z = 24
distance from c-a = 24 (it wraps around)
distance from d-b = 24
You must write a full program that takes two strings from STDIN, and prints a truthy value if they are Caesar equivalent, and a falsy value if they are not.

Valid Input
Since capitalization doesn't matter, it is acceptable if your program requires the input to be all lower-case, all upper-case, or whatever mix you want, as long as this is specified in your answer.

The input will not have spaces or punctuation.

The inputs will be the same length.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool
equiv(const char *s, const char *t)
{
	size_t i;
	int c0, c1;
	int d0, d1;

	for (i = 0; s[i] && t[i]; i++) {
		c0 = tolower(s[i]);
		c1 = tolower(t[i]);
		if (!isalpha(c0) || !isalpha(c1))
			return false;

		d1 = c1 - c0;
		if (c0 > c1)
			d1 += 26;

		if (i == 0)
			d0 = d1;

		if (d0 != d1)
			return false;
	}
	return !s[i] && !t[i];
}

int
main()
{
	assert(equiv("Abc", "Cde") == true);
	assert(equiv("Hello", "World") == false);
	assert(equiv("Abcd", "Yzab") == true);

	return 0;
}
