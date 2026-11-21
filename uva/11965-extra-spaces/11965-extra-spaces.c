#include <stdio.h>

void
solve(const char *s)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] == ' ') {
			while (s[i] && s[i] == ' ')
				i++;
			i--;
			putchar(' ');
		} else
			putchar(s[i]);
	}
	puts("");
}

int
main()
{
	const char *s1 =
	    "Sample test one:\n"
	    "  there was 2 spaces and\n"
	    "here are also  2  spaces";

	const char *s2 =
	    "Sample test two:\n"
	    "    there was 4 spaces";

	solve(s1);
	solve(s2);

	return 0;
}
