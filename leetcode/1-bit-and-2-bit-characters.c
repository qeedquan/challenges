/*

We have two special characters. The first character can be represented by one bit 0. The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not. The given string will always end with a zero.

Note:
1 <= len(bits) <= 1000.
bits[i] is always 0 or 1.

*/

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

bool
onebit(int *a, size_t n)
{
	size_t i;
	bool b;

	b = true;
	for (i = 0; i < n; i++) {
		b = true;
		if (a[i] == 1) {
			i = i + 1;
			b = false;
		}
	}
	return b;
}

int
main(void)
{
	int a1[] = {1, 0, 0};
	int a2[] = {1, 1, 1, 0};

	assert(onebit(a1, nelem(a1)) == true);
	assert(onebit(a2, nelem(a2)) == false);

	return 0;
}
