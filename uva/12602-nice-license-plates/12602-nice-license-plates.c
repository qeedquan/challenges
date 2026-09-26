#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
base26(const char *input)
{
	int result;

	result = (input[2] - 'A');
	result += 26 * (input[1] - 'A');
	result += 676 * (input[0] - 'A');
	return result;
}

bool
nice(const char *license)
{
	char left[4];
	int right;

	memset(left, 0, sizeof(left));
	if (sscanf(license, "%3s-%d", left, &right) != 2)
		return false;
	return abs(base26(left) - right) <= 100;
}

int
main()
{
	assert(nice("ABC-0123") == true);
	assert(nice("AAA-9999") == false);

	return 0;
}
