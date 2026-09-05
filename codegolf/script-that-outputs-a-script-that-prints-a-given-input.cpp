/*

Write a piece of code that takes a string as input, and outputs a piece of code in the same language that, when run, will output the initial input string.

It must be able to handle any combination of characters A-Z, a-z, and 0-9.

Example in Python:

import sys
print "print('" + sys.argv[1]  + "')"
Given the input of testing123, it will return print('testing123').

Since this is code-golf, the shortest answer in bytes will win.

*/

#include <cstdio>

auto CODE = R"(
#include <stdio.h>

int main(void)
{
	printf("%%s\n", "%s");
	return 0;
}

)";

int main(int argc, char *argv[])
{
	auto text = (argc >= 2) ? argv[1] : "";
	printf(CODE, text);
	return 0;
}
