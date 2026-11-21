/*

The trim() method removes whitespace from both sides of a string. w3schools

In this kata we are going to extend the trim method to be able to remove any character(upper and lower cases) from both sides of a string.
Task:
Create a method called trim which removes the passed parameter c(upper and lower cases) from the leading and tailing of the string.

Note:
1- If no parameter is being passed you need to remove the leading and tailing spaces.
2- The passed parameter will only be alphabet(upper and lower cases) characters.

Examples:
string = "LLLHello Worldlll" and c = "l" => "Hello World"

string = "Visca ElbarcaXxX" and c = "X" => "Visca Elbarca"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
trim(char *s, char c)
{
	size_t i, n;

	c = tolower(c);
	i = 0;
	while (s[i] && tolower(s[i]) == c)
		i++;

	n = i + strlen(s + i);
	while (n > 0 && tolower(s[n - 1]) == c)
		n--;

	memmove(s, s + i, n - i);
	s[n - i] = '\0';
	return s;
}

void
test(char *s, int c, const char *r)
{
	trim(s, c);
	puts(s);
	assert(!strcmp(s, r));
}

int
main()
{
	char s1[] = "LLLHello Worldlll";
	char s2[] = "Visca ElbarcaXxX";
	char s3[] = "";
	char s4[] = "   Hello World                 ";
	char s5[] = "xxxxxxxxxxxxxxxxxxxy";
	char s6[] = "yzzzzzzzzzzz";
	char s7[] = "yaaaaaaaaaaaaaaaaaa";

	test(s1, 'l', "Hello World");
	test(s2, 'X', "Visca Elbarca");
	test(s3, ' ', "");
	test(s4, ' ', "Hello World");
	test(s5, 'x', "y");
	test(s6, 'z', "y");
	test(s7, 'y', "aaaaaaaaaaaaaaaaaa");

	return 0;
}
