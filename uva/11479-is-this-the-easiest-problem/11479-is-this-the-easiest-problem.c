#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef long long vlong;

const char *
type(vlong x, vlong y, vlong z)
{
	if (x <= 0 || y <= 0 || z <= 0)
		return "Invalid";
	if (x + y <= z)
		return "Invalid";
	if (y + z <= x)
		return "Invalid";
	if (x + z <= y)
		return "Invalid";
	if (x == y && y == z)
		return "Equilateral";
	if ((x == y && x != z) || (x == z && x != y) || (y == z && x != y))
		return "Isosceles";
	return "Scalene";
}

void
test(vlong x, vlong y, vlong z, const char *r)
{
	assert(!strcmp(type(x, y, z), r));
}

int
main()
{
	test(1, 2, 5, "Invalid");
	test(1, 1, 1, "Equilateral");
	test(4, 4, 2, "Isosceles");
	test(3, 4, 5, "Scalene");

	return 0;
}
