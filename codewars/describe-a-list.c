/*

Write function describeList which returns "empty" if the list is empty or "singleton" if it contains only one element or "longer"" if more.

*/

#include <stdio.h>

const char *
describe(size_t len)
{
	if (len == 0)
		return "empty";
	if (len == 1)
		return "singleton";
	return "longer";
}

int
main()
{
	size_t len;

	for (len = 0; len <= 10; len++)
		printf("%zu: %s\n", len, describe(len));
	return 0;
}
