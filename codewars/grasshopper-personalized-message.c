/*

Create a function that gives a personalized greeting. This function takes two parameters: name and owner.

Use conditionals to return the proper message:

case                   return
name equals owner       'Hello boss'
otherwise               'Hello guest'

*/

#include <stdio.h>
#include <string.h>

const char *
greet(const char *name, const char *owner)
{
	if (!strcmp(name, owner))
		return "Hello boss";
	return "Hello guest";
}

int
main()
{
	puts(greet("Bob", "Bob"));
	puts(greet("Bob", "Xke"));
	return 0;
}
