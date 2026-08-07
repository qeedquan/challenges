/*

Create a function which answers the question "Are you playing banjo?".
If your name starts with the letter "R" or lower case "r", you are playing banjo!

The function takes a name as its only argument, and returns one of the following strings:

name + " plays banjo"
name + " does not play banjo"
Names given are always valid strings.

*/

#include <stdio.h>
#include <ctype.h>

char *
banjo(const char *name, char *output)
{
	if (tolower(name[0]) == 'r')
		sprintf(output, "%s plays banjo", name);
	else
		sprintf(output, "%s does not play banjo", name);
	return output;
}

int
main()
{
	char buf[32];

	printf("%s\n", banjo("Tex", buf));
	printf("%s\n", banjo("Rich", buf));

	return 0;
}
