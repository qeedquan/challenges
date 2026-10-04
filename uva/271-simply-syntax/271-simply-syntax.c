#include <assert.h>
#include <stdio.h>
#include <string.h>

bool
check(const char *s)
{
	size_t i, n;
	int r;

	n = strlen(s);
	r = 0;
	for (i = n; i > 0; i--) {
		switch (s[i - 1]) {
		case 'p' ... 'z':
			r += 1;
			break;

		case 'N':
			if (r == 0)
				return false;
			break;

		case 'C':
		case 'D':
		case 'E':
		case 'I':
			if (r < 2)
				return false;
			r -= 1;
			break;

		default:
			return false;
		}
	}
	return r == 1;
}

int
main()
{
	assert(check("Cp") == false);
	assert(check("Isz") == true);
	assert(check("NIsz") == true);
	assert(check("Cqpq") == false);

	return 0;
}
