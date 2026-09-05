/*

Paul is one of your Belgian acquaintances, and he would like you to create a program that outputs at least one of the following five strings:

12496=>14288=>15472=>14536=>14264

14264=>12496=>14288=>15472=>14536

14536=>14264=>12496=>14288=>15472

15472=>14536=>14264=>12496=>14288

14288=>15472=>14536=>14264=>12496
It represents the friends he's most proud of, and he would like to eat with them. Paul also thinks that the number 6 is perfect, and that is the only number worth using. So you cannot use any other digit than "6" in your code (0 to 5 and 7 to 9 are forbidden). Your program cannot take any inputs. The output can contain garbage before and/or after the string but should contain at least one of the above strings.

For example this is a valid output :

220frefze
f**14288=>15472=>14536=>14264=>12496**fczfe fz**15472=>14536=>14264=>12496=>14288**zfe
fzehth
I "ligthly" hinted in the question as how I expect this to be resolved, but how knows ? Maybe there is a better way... Hope you have fun.

This is code-golf : lowest score in bytes wins.

*/

#include <stdio.h>

// ported from @cleblanc solution
void
output()
{
	static const char enc[] = "mnpuryzmpnttyzmqpsnyzmpqoryzmpnrp";

	const char *p;

	for (p = enc; *p; p++)
		putchar(*p - 66 + 6);
	putchar('\n');
}

int
main()
{
	output();
	return !6;
}
