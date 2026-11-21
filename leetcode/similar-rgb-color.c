/*

The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.

For example, "#15c" is shorthand for the color "#1155cc".
The similarity between the two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)2 - (CD - WX)2 - (EF - YZ)2.

Given a string color that follows the format "#ABCDEF", return a string represents the color that is most similar to the given color and has a shorthand (i.e., it can be represented as some "#XYZ").

Any answer which has the same highest similarity as the best answer will be accepted.

Example 1:

Input: color = "#09f166"
Output: "#11ee66"
Explanation:
The similarity is -(0x09 - 0x11)2 -(0xf1 - 0xee)2 - (0x66 - 0x66)2 = -64 -9 -0 = -73.
This is the highest among any shorthand color.
Example 2:

Input: color = "#4e3fe1"
Output: "#5544dd"

Constraints:

color.length == 7
color[0] == '#'
color[i] is either digit or character in the range ['a', 'f'] for i > 0.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
dist2(int x, int y)
{
	return (x - y) * (x - y);
}

char *
similar(const char *s, char *b)
{
	static const unsigned hex[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};

	unsigned c[3], r[3];
	size_t i, j;
	int d, m;

	if (sscanf(s, "#%02X%02X%02X", &c[0], &c[1], &c[2]) != 3)
		return NULL;

	for (i = 0; i < 3; i++) {
		m = INT_MAX;
		for (j = 0; j < nelem(hex); j++) {
			d = dist2(c[i], hex[j]);
			if (d < m) {
				r[i] = hex[j];
				m = d;
			}
		}
	}
	sprintf(b, "#%02x%02x%02x", r[0], r[1], r[2]);

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128], *p;

	p = similar(s, b);
	assert(p != NULL);
	printf("%s\n", p);
	assert(!strcmp(p, r));
}

int
main(void)
{
	test("#09f166", "#11ee66");
	test("#4e3fe1", "#5544dd");
	test("#778899", "#778899");
	test("#000000", "#000000");

	return 0;
}
