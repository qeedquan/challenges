/*

Description
You have clothes international size as text (xs, s, xxl).
Your goal is to return European number size as a number from that size.

Notice that there is arbitrary amount of modifiers (x), excluding m size, and input can be any string.

Linearity
Base size for medium (m) is 38.
(then, small (s) is 36, and large (l) is 40)

The scale is linear; modifier x continues that by adding or subtracting 2 from resulting size.

(For sizes where x modifier makes total size negative, treat that as OK, and return negative size)

Invalid cases
Function should handle wrong/invalid sizes.

Valid input has any base size (s/m/l) and any amount of modifiers (x) before base size (like xxl).
Notice that you cannot apply modifier for m size, consider that case as invalid!
Anything else is disallowed and should be considered as invalid (None for Python, 0, false for Go, null for JavaScript).

Invalid examples: xxx, sss, xm, other string

Valid Examples
xs: 34
s: 36
m: 38
l: 40
xl: 42

*/

#include <assert.h>

int
clothsize(const char *s)
{
	int m;

	for (m = 0; *s == 'x'; s++)
		m += 2;

	if (!s[0] || s[1])
		return -1;

	switch (*s) {
	case 's':
		return 36 - m;

	case 'm':
		if (!m)
			return 38;
		break;

	case 'l':
		return 40 + m;
	}
	return -1;
}

int
main()
{
	assert(clothsize("xs") == 34);
	assert(clothsize("s") == 36);
	assert(clothsize("m") == 38);
	assert(clothsize("l") == 40);
	assert(clothsize("xl") == 42);

	return 0;
}
