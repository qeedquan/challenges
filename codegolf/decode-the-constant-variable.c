/*

To save codepoints, a compute-er can share 0 and -, and share . with $(indicating a variable name).

A number matches RegEx /^-?(0|[1-9]\d*)(\.\d+)?$/ and a variable matches RegEx /^\$\d+$/.

Given input where 0 and - are represented as same char(your choice) and so do . and $, return as number or variable. You can assume that it's possible.

Test cases
0 => 0
10 => 10
01 => -1
00 => -0
001 => (undefined behavior)
1.3 => 1.3
.33 => $33
0.33 => 0.33
00.33 => -0.33
42.0 => 42.0
3.4.5 => (undefined behavior)
Shortest code wins.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
decode(char *string)
{
	if (string[0] != '0' || strchr(".$", string[1])) {
		if (string[0] == '.')
			string[0] = '$';
	} else
		string[0] = '-';
}

void
test(const char *string, const char *expected)
{
	char *result;

	result = strdup(string);
	assert(result);
	decode(result);
	assert(!strcmp(expected, "") || !strcmp(result, expected));
	free(result);
}

int
main()
{
	test("0", "0");
	test("10", "10");
	test("01", "-1");
	test("00", "-0");
	test("001", "");
	test("1.3", "1.3");
	test(".33", "$33");
	test("0.33", "0.33");
	test("00.33", "-0.33");
	test("42.0", "42.0");
	test("3.4.5", "");

	return 0;
}
