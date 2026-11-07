#include <assert.h>
#include <string.h>

const char *
shape(int a, int b, int c, int d)
{
	if (a == b && b == c && c == d)
		return "square";
	if (a == c && b == d)
		return "rectangle";
	if ((a + b + c > d) && (a + b + d > c) && (a + c + d > b) && (b + c + d > a))
		return "quadrangle";
	return "banana";
}

int
main(void)
{
	assert(!strcmp(shape(10, 8, 7, 6), "quadrangle"));
	assert(!strcmp(shape(9, 1, 9, 1), "rectangle"));
	assert(!strcmp(shape(29, 29, 29, 29), "square"));
	assert(!strcmp(shape(5, 12, 30, 7), "banana"));

	return 0;
}
