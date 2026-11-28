#include <assert.h>
#include <string.h>

const char *
winner(int n)
{
	if (!(n & (n - 1)))
		return "Alice";
	return "Bob";
}

int
main()
{
	assert(!strcmp(winner(2), "Alice"));
	assert(!strcmp(winner(3), "Bob"));
	assert(!strcmp(winner(4), "Alice"));

	return 0;
}
