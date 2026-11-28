/*

Given a string and a char, add an underscore (_, which won't appear in the input) before any one instance of the char, case-insensitive; if the char never appears in the string, append the char to the end surrounded by ().

https://i.sstatic.net/QJQk9PnZ.png

You can assume ASCII input, though the screenshot isn't.

Shortest code in each language wins.

Test cases
Search, S => _Search
Translate, N => Tra_nslate
Cut, X => Cut(X)
Snap 10th, 1 => Snap _10th
Snap 50th, 2 => Snap 50th(2)
Excavate, E => _Excavate or Excavat_e
Cut(X), ( => Cut_(X)
Cut(X), X => Cut(_X)
Cut(X), ) => Cut(X_)
Cut(X), V => Cut(X)(V)
Test, q => Test(q)
Test, ) => Test())

Notes
Test cases here don't necessarily match real hotkeys.
Should I add background?

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
shortcut(const char *input, int anchor, char *output)
{
	char *pointer;
	int flag;

	flag = 0;
	for (pointer = output; *input; input++) {
		if (!flag && tolower(anchor) == tolower(*input)) {
			*pointer++ = '_';
			flag = 1;
		}
		*pointer++ = *input;
	}
	if (!flag)
		pointer += sprintf(pointer, "(%c)", anchor);
	*pointer = '\0';
}

void
test(const char *input, int anchor, const char *expected)
{
	char result[128];

	shortcut(input, anchor, result);
	printf("%s\n", result);
	assert(!strcmp(result, expected));
}

int
main()
{
	test("Search", 'S', "_Search");
	test("Translate", 'N', "Tra_nslate");
	test("Cut", 'X', "Cut(X)");
	test("Snap 10th", '1', "Snap _10th");
	test("Snap 50th", '2', "Snap 50th(2)");
	test("Excavate", 'E', "_Excavate");
	test("Cut(X)", '(', "Cut_(X)");
	test("Cut(X)", 'X', "Cut(_X)");
	test("Cut(X)", ')', "Cut(X_)");
	test("Cut(X)", 'V', "Cut(X)(V)");
	test("Test", 'q', "Test(q)");
	test("Test", ')', "Test())");

	return 0;
}
