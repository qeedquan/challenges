/*

Trollencio changed my code! can you fix it?
My name is not "dumb!" o( TT_TT )o

Instructions: Fix the code

Input
----

    Javatlacati

Output
-----

    Hello my name is Javatlacati

Input
----

    ""

Output
----
    Hello world!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
hello(const char *name, char *output)
{
	if (!name || !name[0])
		sprintf(output, "Hello world!");
	else
		sprintf(output, "Hello my name is %s", name);
	return output;
}

void
test(const char *name, const char *expected)
{
	char output[32];

	hello(name, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Javatlacati", "Hello my name is Javatlacati");
	test("", "Hello world!");
	test(NULL, "Hello world!");

	return 0;
}
