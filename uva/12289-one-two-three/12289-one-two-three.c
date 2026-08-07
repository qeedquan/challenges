#include <assert.h>

int
detect(const char *s)
{
	if (s[0] && s[1] && s[2] && s[3])
		return 3;

	if (s[0] == 'o' && s[1] == 'n' && s[2] == 'e')
		return 1;
	if (s[0] == 'o' && s[1] == 'n')
		return 1;
	if (s[0] == 'o' && s[2] == 'e')
		return 1;
	if (s[1] == 'n' && s[2] == 'e')
		return 1;

	if (s[0] == 't' && s[1] == 'w' && s[2] == 'o')
		return 2;
	if (s[0] == 't' && s[1] == 'w')
		return 2;
	if (s[0] == 't' && s[2] == 'o')
		return 2;
	if (s[1] == 'w' && s[2] == 'o')
		return 2;

	return 0;
}

int
main()
{
	assert(detect("one") == 1);
	assert(detect("two") == 2);
	assert(detect("three") == 3);

	assert(detect("owe") == 1);
	assert(detect("too") == 2);
	assert(detect("theee") == 3);

	return 0;
}
