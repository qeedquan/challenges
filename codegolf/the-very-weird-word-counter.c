/*

INPUT: Any string consisting exclusively of lowercase letters via function argument, command line argument, STDIN, or similar.

OUTPUT: Print or return a number that will represent the sum of the distances of the letters according to the following metric:

You take the first and second letter and count the distance between them. The distance is defined by the QWERTY keyboard layout, where every adjacent letter in the same row has distance 1 and every adjacent letter in the same column has distance 2. To measure the distance between letters that aren't adjacent, you take the shortest path between the two.

Examples:

q->w is 1 distance apart
q->e is 2 distance
q->a is 2 distance
q->s is 3 distance (q->a->s or q->w->s)
q->m is 10 distance
Then you take the second and third letter, then the third and fourth, etc., until you reach the end of the input. The output is the sum of all those distances.

Example input and output:

INPUT: qwer
OUTPUT: 3

INPUT: qsx
OUTPUT: 5

INPUT: qmq
OUTPUT: 20

INPUT: tttt
OUTPUT: 0
Here is an image showing which letters are in the same column:

https://i.stack.imgur.com/77Kzr.png

This is code golf, so the shortest code in bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ported from @Kade solution
int
count(const char *s)
{
	static const char keys[] = "qwertyuiopasdfghjkl zxcvbnm";

	char *p, *q;
	int r, x, y;
	size_t i;

	r = 0;
	for (i = 0; s[i] && s[i + 1]; i++) {
		p = strchr(keys, s[i]);
		q = strchr(keys, s[i + 1]);
		if (!p || !q)
			continue;

		x = p - keys;
		y = q - keys;

		r += abs((x % 10) - (y % 10)) + (2 * abs((x / 10) - (y / 10)));
	}
	return r;
}

int
main(void)
{
	assert(count("qwer") == 3);
	assert(count("qsx") == 5);
	assert(count("qmq") == 20);
	assert(count("tttt") == 0);

	return 0;
}
