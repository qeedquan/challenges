#include <assert.h>
#include <stdio.h>
#include <ctype.h>

bool
loop(const char *s)
{
	size_t f1, f2;
	size_t m1, m2;
	size_t i, t;

	f1 = f2 = 0;
	m1 = m2 = 0;
	t = 0;
	for (i = 0; s[i]; i++) {
		if (isspace(s[i]))
			continue;

		if (s[i] == 'M')
			m1 += 1;
		else
			f1 += 1;

		if (s[i + 1] == 'M')
			m2 += 1;
		else
			f2 += 1;

		if (s[i + 1])
			i += 1;
		t += 1;
	}
	return (m1 == f2 || f1 == m2) && t > 1;
}

int
main()
{
	assert(loop("MF MF") == true);
	assert(loop("FM FF MF MM") == true);
	assert(loop("MM FF") == true);
	assert(loop("MF MF MF MF FF") == false);

	return 0;
}
