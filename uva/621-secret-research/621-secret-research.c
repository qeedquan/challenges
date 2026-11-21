#include <assert.h>
#include <stdio.h>
#include <string.h>

int
solve(const char *s)
{
	size_t n;

	n = strlen(s);
	if (n == 0)
		return '?';
	if (strcmp(s, "1") == 0 || strcmp(s, "4") == 0 || strcmp(s, "78") == 0)
		return '+';
	if (n >= 2 && s[n - 1] == '5' && s[n - 2] == '3')
		return '-';
	if (s[0] == '9' && s[n - 1] == '4')
		return '*';
	if (s[0] == '1' && s[1] == '9' && s[2] == '0')
		return '?';
	return '+';
}

int
main()
{
	assert(solve("78") == '+');
	assert(solve("7835") == '-');
	assert(solve("19078") == '?');
	assert(solve("944") == '*');

	return 0;
}
