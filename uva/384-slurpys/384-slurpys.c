#include <assert.h>
#include <stdio.h>
#include <string.h>

int
slump(const char **s)
{
	if (**s != 'D' && **s != 'E')
		return 0;

	*s += 1;
	if (**s != 'F')
		return 0;

	while (**s == 'F')
		*s += 1;

	if (**s == 'G') {
		*s += 1;
		return 1;
	}
	return slump(s);
}

int
slimp(const char **s)
{
	int f;

	if (**s != 'A')
		return 0;

	*s += 1;
	if (**s == 'H') {
		*s += 1;
		return 1;
	}

	if (**s == 'B') {
		*s += 1;
		f = slimp(s) && **s == 'C';
		*s += 1;
		return f;
	}

	f = slump(s) && **s == 'C';
	*s += 1;
	return f;
}

const char *
solve(const char *s)
{
	slimp(&s);
	slump(&s);
	if (*s == '\0')
		return "YES";
	return "NO";
}

void
test(const char *s, const char *r)
{
	assert(!strcmp(solve(s), r));
}

int
main()
{
	test("AHDFG", "YES");
	test("DFGAH", "NO");

	return 0;
}
