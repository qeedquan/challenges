/*

You're writing code to control your town's traffic lights. You need a function to handle each change from green, to yellow, to red, and then to green again.

Complete the function that takes a string as an argument representing the current state of the light and returns a string representing the state the light should change to.

For example, update_light('green') should return 'yellow'.

Note: Use "" instead of '' in C++.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

const char *
updatelight(const char *current)
{
	if (!strcmp(current, "green"))
		return "yellow";
	if (!strcmp(current, "yellow"))
		return "red";
	return "green";
}

int
main()
{
	puts(updatelight("green"));
	puts(updatelight("yellow"));
	puts(updatelight("red"));
	return 0;
}
