/*

The code provided is supposed to simply return the named number as an integer.

But it's not working properly.

## Task

Fix the bug so we can all go home early.

## Notes

* Don't try to modify the `getNumber` API. It returns an enum.

*/

#include <assert.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
number(const char *s)
{
	static const char *nums[] = {
		"one", "ichi", "un",
		"two", "ni", "deux",
		"three", "san", "trois",
		"four", "shi", "quatre"
	};

	static const int vals[] = {
		1, 1, 1,
		2, 2, 2,
		3, 3, 3,
		4, 4, 4
	};

	size_t i;

	for (i = 0; i < nelem(nums); i++) {
		if (!strcmp(s, nums[i]))
			return vals[i];
	}
	return -1;
}

int
main()
{
	assert(number("one") == 1);
	assert(number("two") == 2);
	assert(number("three") == 3);
	assert(number("four") == 4);

	assert(number("ichi") == 1);
	assert(number("ni") == 2);
	assert(number("san") == 3);
	assert(number("shi") == 4);

	assert(number("un") == 1);
	assert(number("deux") == 2);
	assert(number("trois") == 3);
	assert(number("quatre") == 4);

	return 0;
}
