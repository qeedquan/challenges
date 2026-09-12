/*

Return a function that will trim a string (the first argument given) if it is longer than the maximum string length (the second argument given). The result should also end with "..."

These dots at the end also add to the string length.

So in the above example, trim("Creating kata is fun", 14) should return "Creating ka..."

If the maximum string length is smaller than or equal to 3 characters, then the length of the dots is not added to the string length.

e.g. trim("He", 1) should return "H...", because 1 <= 3

If the string is smaller or equal than the maximum string length, then simply return the string with no trimming or dots required.

e.g. trim("Code Wars is pretty rad", 50) should return "Code Wars is pretty rad"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
trim(const char *input, size_t size, char *output)
{
	size_t length;
	size_t index;
	size_t offset;

	length = strlen(input);
	if (length <= size)
		strcpy(output, input);
	else {
		offset = (size <= 3) ? 0 : 3;
		for (index = 0; index < size - offset; index++)
			output[index] = input[index];
		sprintf(output + index, "...");
	}
	return output;
}

void
test(const char *input, size_t size, const char *expected)
{
	char output[128];

	trim(input, size, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test("Creating kata is fun", 14, "Creating ka...");
	test("He", 1, "H...");
	test("Code Wars is pretty rad", 50, "Code Wars is pretty rad");
	return 0;
}
