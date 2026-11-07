#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
kbenc(const char *s, char *b)
{
	static const char layout[] = "qwertyuiop[asdfghjkl;zxcvbnm,  ";

	size_t i;
	char *p;

	for (i = 0; (b[i] = s[i]); i++) {
		p = strchr(layout, tolower(s[i]));
		if (p)
			b[i] = isupper(s[i]) ? toupper(p[1]) : p[1];
	}

	return b;
}

void
test(const char *s, const char *r)
{
	char b[128];

	kbenc(s, b);
	printf("%s\n", b);
	assert(!strcasecmp(b, r));
}

int
main(void)
{
	test("Foo Foo Bar Bar Python", "Gpp Gpp Nst Nst [uyjpm");
	test("Case does not matter", "vSDR fprd mpy ,sYYrT");

	return 0;
}
