/*

Given a string of characters, create a function returning the middle number in the product of each digit in the string.

Example: 's7d8jd9' -> 7, 8, 9 -> 7*8*9=504, thus 0 should be returned as an integer.

Not all strings will contain digits and not all inputs will be string. In those cases, return -1.

If the product has an even number of digits, return the middle two digits

Example: 1563 -> 56

NOTE: Remove leading zeros if product is even and the first digit of the two is a zero. Example 2016 -> 1

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int
middle(const char *s)
{
	int r, m;
	size_t n;

	if (!s)
		return -1;

	r = 1;
	for (n = 0; *s; s++) {
		if (isdigit(*s)) {
			r *= (*s - '0');
			n += 1;
		}
	}
	if (n == 0)
		return -1;

	if (n % 2) {
		n /= 2;
		m = 10;
	} else {
		n = (n - 1) / 2;
		m = 100;
	}

	r /= pow(10, n);
	r %= m;
	return r;
}

int
main()
{
	assert(middle("s7d8jd9") == 0);
	assert(middle("58jd9fgh/fgh6s.,sdf") == 16);
	assert(middle(NULL) == -1);
	assert(middle("") == -1);
	assert(middle("not a string") == -1);

	return 0;
}
