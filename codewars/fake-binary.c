/*

Given a string of digits, you should replace any digit below 5 with '0' and any digit 5 and above with '1'. Return the resulting string.

Note: input will never be an empty string

*/

#include <stdio.h>

char *
fakebin(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i]; i++) {
		if (s[i] < '5')
			b[i] = '0';
		else if (s[i] >= '5')
			b[i] = '1';
		else
			b[i] = s[i];
	}
	return b;
}

int
main()
{
	char b[128];

	printf("%s\n", fakebin("555444", b));
	return 0;
}
