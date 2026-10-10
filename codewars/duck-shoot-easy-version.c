/*

You've arrived at a carnival and head straight for the duck shooting tent. Why wouldn't you?

You will be given a set amount of ammo, and an aim rating of between 1 and 0. No your aim is not always perfect - hey maybe someone fiddled with the sights on the gun...

Anyway your task is to calculate how many successful shots you will be able to make given the available ammo and your aim score, then return a string representing the pool of ducks, with those ducks shot marked with 'X' and those that survived left unchanged. You will always shoot left to right.

Example of start and end duck string with two successful shots:

Start ---> |~~~~~22~2~~~~~|

Bang!! Bang!!

End ---> |~~~~~XX~2~~~~~|

All inputs will be correct type and never empty.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

void
duckshoot(int ammo, double aim, const char *ducks, char *output)
{
	int count;

	for (count = ammo * aim; *ducks; ducks++) {
		*output = *ducks;
		if (count > 0 && *output == '2') {
			*output = 'X';
			count -= 1;
		}
		output++;
	}
	*output = '\0';
}

void
test(int ammo, double aim, const char *ducks, const char *expected)
{
	char output[128];

	duckshoot(ammo, aim, ducks, output);
	puts(output);
	assert(!strcmp(output, expected));
}

int
main()
{
	test(4, 0.64, "|~~2~~~22~2~~22~2~~~~2~~~|", "|~~X~~~X2~2~~22~2~~~~2~~~|");
	test(9, 0.22, "|~~~~~~~2~2~~~|", "|~~~~~~~X~2~~~|");
	test(6, 0.41, "|~~~~~22~2~~~~~|", "|~~~~~XX~2~~~~~|");
	test(8, 0.05, "|2~~~~|", "|2~~~~|");
	test(8, 0.92, "|~~~~2~2~~~~~22~~2~~~~2~~~2|", "|~~~~X~X~~~~~XX~~X~~~~X~~~X|");

	return 0;
}
