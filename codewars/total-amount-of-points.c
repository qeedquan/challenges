/*

Our football team finished the championship. The result of each match look like "x:y". Results of all matches are recorded in the collection.

For example: ["3:1", "2:2", "0:1", ...]

Write a function that takes such collection and counts the points of our team in the championship. Rules for counting points for each match:

if x>y - 3 points
if x<y - 0 point
if x=y - 1 point
Notes:

there are 10 matches in the championship
0 <= x <= 4
0 <= y <= 4

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
points(const char **s, size_t n)
{
	int r, x, y;
	size_t i;

	r = 0;
	for (i = 0; i < n; i++) {
		if (sscanf(s[i], "%d:%d", &x, &y) != 2)
			continue;

		if (x > y)
			r += 3;
		else if (x == y)
			r += 1;
	}
	return r;
}

int
main()
{
	const char *s1[] = { "1:0", "2:0", "3:0", "4:0", "2:1", "3:1", "4:1", "3:2", "4:2", "4:3" };
	const char *s2[] = { "1:1", "2:2", "3:3", "4:4", "2:2", "3:3", "4:4", "3:3", "4:4", "4:4" };
	const char *s3[] = { "0:1", "0:2", "0:3", "0:4", "1:2", "1:3", "1:4", "2:3", "2:4", "3:4" };
	const char *s4[] = { "1:0", "2:0", "3:0", "4:0", "2:1", "1:3", "1:4", "2:3", "2:4", "3:4" };
	const char *s5[] = { "1:0", "2:0", "3:0", "4:4", "2:2", "3:3", "1:4", "2:3", "2:4", "3:4" };

	assert(points(s1, nelem(s1)) == 30);
	assert(points(s2, nelem(s2)) == 10);
	assert(points(s3, nelem(s3)) == 0);
	assert(points(s4, nelem(s4)) == 15);
	assert(points(s5, nelem(s5)) == 12);

	return 0;
}
