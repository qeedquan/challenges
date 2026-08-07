/*

Your friend has been out shopping for puppies (what a time to be alive!)... He arrives back with multiple dogs, and you simply do not know how to respond!

By repairing the function provided, you will find out exactly how you should respond, depending on the number of dogs he has.

The number of dogs will always be a number and there will always be at least 1 dog.

*/

#include <assert.h>
#include <string.h>

const char *
dalmatians(int n)
{
	if (n < 11)
		return "Hardly any";
	if (n < 51)
		return "More than a handful!";
	if (n == 101)
		return "101 DALMATIANS!!!";
	return "Woah that's a lot of dogs!";
}

void
test(const char *a, const char *b)
{
	assert(!strcmp(a, b));
}

int
main()
{
	test("More than a handful!", dalmatians(26));
	test("Hardly any", dalmatians(8));
	test("More than a handful!", dalmatians(14));
	test("Woah that's a lot of dogs!", dalmatians(80));
	test("Woah that's a lot of dogs!", dalmatians(100));
	test("101 DALMATIANS!!!", dalmatians(101));

	return 0;
}
