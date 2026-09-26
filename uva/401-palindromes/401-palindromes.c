#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

void
solve(const char *s)
{
	static const char sym1[] = "A   3  HIL JM O   2TUVWXY5";
	static const char sym2[] = "01SE Z  8 ";

	ssize_t i, j, len;
	int flag1, flag2;

	len = strlen(s);
	flag1 = 0;
	flag2 = 0;
	for (i = 0, j = len - 1; i <= j; i++, j--) {
		if (s[i] != s[j])
			flag1 = 1;

		if ('A' <= s[i] && s[i] <= 'Z') {
			if (s[j] != sym1[s[i] - 'A'])
				flag2 = 1;
		} else if ('0' <= s[i] && s[i] <= '9') {
			if (s[j] != sym2[s[i] - '0'])
				flag2 = 1;
		}
	}

	printf("%s -- is ", s);
	if (flag1) {
		if (flag2)
			puts("not a palindrome.");
		else
			puts("a mirrored string.");
	} else {
		if (flag2)
			puts("a regular palindrome.");
		else
			puts("a mirrored palindrome.");
	}
}

int
main()
{
	solve("NOTAPALINDROME");
	solve("ISAPALINILAPASI");
	solve("2A3MEAS");
	solve("ATOYOTA");

	return 0;
}
