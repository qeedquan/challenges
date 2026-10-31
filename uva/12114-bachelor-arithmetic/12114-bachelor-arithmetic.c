#include <assert.h>
#include <string.h>

const char *
state(int b, int s)
{
	if (b == 0 || b == 1)
		return ":-\\";
	if (s >= b)
		return ":-|";
	return ":-(";
}

int
main(void)
{
	assert(!strcmp(state(10, 10), ":-|"));
	assert(!strcmp(state(2, 3), ":-|"));
	assert(!strcmp(state(3, 2), ":-("));
	assert(!strcmp(state(1, 0), ":-\\"));

	return 0;
}
