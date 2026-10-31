/*

In a language of your choice, write a program that exactly outputs the characters Hello world! followed by a newline. The code:

should not use any character more than twice (alphanumeric, symbol, whitespace...anything)
should not use any external resources
should not use any user input
should not output anything else

An example of a valid python program:

print("He%so world!"%(2*'l'))
An example of an invalid python program (the character 'r' is used three times):

print("Hel"+chr(108)+'o world!')

*/

#include <stdio.h>

int
main()
{
	printf("He%s%co world!\n", "l", 'k' + 1);
	return 0;
}
