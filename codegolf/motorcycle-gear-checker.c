/*

Some of you may be familiar with the way that a motorcycle shifts. But for those who don't, It looks like this

6

5

4

3

2

N

1

Now I want to know what gear I am in after performing a few up and down shifts. The program should work from neutral.

Sample input:

V^^
Sample output:

2
As you can see I downshifted once from N to 1 and upshifted twice to 2nd gear.

This is a code golf. Shortest answer in bytes wins.

Note: The input can be any 2 characters. Can be U and D for up and down or whatever you want it has to be a string. You cannot shift beyond 1st or 6th gear. If you are in 6th and upshift again it will stay in 6th. Good luck!

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
shift(const char *s)
{
	static const int gears[] = { '1', 'N', '2', '3', '4', '5', '6' };

	size_t i;

	for (i = 1; *s; s++) {
		if (*s == 'V' && i > 0)
			i--;
		else if (*s == '^' && i < nelem(gears) - 1)
			i++;
	}
	return gears[i];
}

int
main()
{
	assert(shift("V^^") == '2');
	assert(shift("V^^^") == '3');
	assert(shift("^^^^^^^^^^^^") == '6');
	assert(shift("VVVVVVVVVVVVVVVVVVVVVVVV") == '1');

	return 0;
}
