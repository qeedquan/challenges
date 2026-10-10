/*

In the C programming language, arrays are defined like this:

int foo[] = {4, 8, 15, 16, 23, 42};      //Foo implicitly has a size of 6
The size of the array is inferred from the initializing elements, which in this case is 6. You can also write a C array this way, explicitly sizing it then defining each element in order:

int foo[6];        //Give the array an explicit size of 6
foo[0] = 4;
foo[1] = 8;
foo[2] = 15;
foo[3] = 16;
foo[4] = 23;
foo[5] = 42;
The challenge
You must write a program or function that expands arrays from the first way to the second. Since you are writing a program to make code longer, and you love irony, you must make your code as short as possible.

The input will be a string representing the original array, and the output will be the expanded array-definition. You can safely assume that the input will always look like this:

<type> <array_name>[] = {<int>, <int>, <int> ... };
"Type" and "array_name" will made up entirely of alphabet characters and underscores _. The elements of the list will always be a number in the range -2,147,483,648 to 2,147,483,647. Inputs in any other format do not need to be handled.

The whitespace in your output must exactly match the whitespace in the test output, although a trailing newline is allowed.

Test IO:
#in
short array[] = {4, 3, 2, 1};

#out
short array[4];
array[0] = 4;
array[1] = 3;
array[2] = 2;
array[3] = 1;


#in
spam EGGS[] = {42};

#out
spam EGGS[1];
EGGS[0] = 42;


#in
terrible_long_type_name awful_array_name[] = {7, -8, 1337, 0, 13};

#out
terrible_long_type_name awful_array_name[5];
awful_array_name[0] = 7;
awful_array_name[1] = -8;
awful_array_name[2] = 1337;
awful_array_name[3] = 0;
awful_array_name[4] = 13;
Submissions in any language are encouraged, but bonus points if you can do it in C.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
expand(const char *source, char *buffer)
{
	char *type, *name;
	char *elements, *pointer;
	size_t length;
	size_t count;
	size_t index;
	int status;
	int value;
	int next;

	status = 0;
	length = strlen(source);
	type = strdup(source);
	name = strdup(source);
	elements = calloc(length + 128, length);
	if (!type || !name || !elements)
		goto error;
	if (sscanf(source, "%s %[^[]s", type, name) != 2)
		goto error;

	pointer = elements;
	count = 0;
	index = 0;
	while (sscanf(source + index, "%*[^-0-9]%d%n", &value, &next) == 1) {
		pointer += sprintf(pointer, "%s[%zu] = %d;\n", name, count, value);
		index += next;
		count += 1;
	}

	sprintf(buffer, "%s %s[%zu];\n%s\n", type, name, count, elements);

	if (0) {
	error:
		status = -1;
	}
	free(type);
	free(name);
	free(elements);

	return status;
}

void
test(const char *source)
{
	char buffer[1024];

	expand(source, buffer);
	printf("%s\n", buffer);
}

int
main()
{
	test("int foo[] = {4, 8, 15, 16, 23, 42};");
	test("short array[] = {4, 3, 2, 1};");
	test("spam EGGS[] = {42};");
	test("terrible_long_type_name awful_array_name[] = {7, -8, 1337, 0, 13};");

	return 0;
}
