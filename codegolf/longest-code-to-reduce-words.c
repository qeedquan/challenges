/*

Write a code in your favorite language which reduces words To first three characters.

Input  : One word
Output : First three letters
For example

INPUT  : ProGramming
OUTPUT : Pro

INPUT  : puZZles
OUTPUT : puZ

INPUT  : BoWling
OUTPUT : BoW
Output needs to be case sensitive

Rule-1
All statements should be meaningful and useful.
For example
the C++ snippet below surely increases the score but is unnecessary.
The similar code snippets below is banned.

std::cout<<"abcabc";
std::cout<<"\b\b\b\b\b\b";
Rule-2
Do not use infinite add-subtract or multiplication-division (or any other kind of) infinite progressions to increase the score.
For example
The similar code snippets below is banned.

if(strcmp(str,"monday")==0)  //The function strcmp() returns 0 if both
                             //strings are same (including NULL character)
cout<<110+1-1+1-1+1-1....inf //110 is ASCII value of 'm'
Winner
Winner will be chosen on the basis of score (Most score wins) after 4 days from now.
If there is a tie then the one who submitted the answer first is the winner

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
reduce(const char *s, char *b)
{
	size_t i;

	for (i = 0; s[i] && i < 3; i++)
		b[i] = s[i];
	b[i] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[4];

	reduce(s, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("ProGramming", "Pro");
	test("puZZles", "puZ");
	test("BoWling", "BoW");

	return 0;
}
