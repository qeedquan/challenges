#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void
base_2(int number, char **output)
{
	if (number > 0) {
		base_2(-number / 2, output);
		*output += sprintf(*output, "%d", number % 2);
	} else if (number < 0) {
		base_2(-number / 2 + !!(number % 2), output);
		*output += sprintf(*output, "%d", abs(number % 2));
	}
}

void
solve(int number, char *output)
{
	if (number == 0)
		sprintf(output, "0");
	else
		base_2(number, &output);
}

void
test(int number, const char *expected)
{
	char output[32];

	solve(number, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(1, "1");
	test(7, "11011");
	test(-2, "10");
	test(0, "0");
	test(-1, "11");
	test(4, "100");
	test(1332, "10101110100");
	test(-4052, "11000001111100");

	return 0;
}
