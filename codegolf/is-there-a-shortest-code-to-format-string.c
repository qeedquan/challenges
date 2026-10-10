/*

Given a string of 10 characters: 'abcdefghij'

I want to format it in this pattern and print it in the console in a minimum number of characters: (abc) def-ghij

My solution:

print(f"({s[0:3]}) {s[3:6]}-{s[6::]}")

*/

#include <stdio.h>

void
format(const char *s)
{
	printf("(%.3s) %.3s-%.4s\n", s, s + 3, s + 6);
}

int
main(void)
{
	format("abcdefghij");
	return 0;
}
