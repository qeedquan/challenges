/*

The following code is 47 characters.

print(("Ekki v","V")["COV"in input()]+"eikur!")
How can it be reduced to 46 or less?

I have even been brainstorming bitwise tricks but can not think of any way to do this. I am starting to think it is not possible to reduce this any further.

One idea I had was

print('Ekki veikur!'[4*('COV'in input()):])
but this does not correctly output the capital letter for Veikor.

*/

#include <stdio.h>
#include <string.h>

const char *
gauge(const char *s)
{
	if (strstr(s, "COV"))
		return "Veikur!";
	return "Ekki veikur!";
}

int
main()
{
	printf("%s\n", gauge("COV"));
	printf("%s\n", gauge(""));

	return 0;
}
