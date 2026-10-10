/*

The borrowers are tiny tiny fictional people. As tiny tiny people they have to be sure they aren't spotted, or more importantly, stepped on.

As a result, the borrowers talk very very quietly. They find that capitals and punctuation of any sort lead them to raise their voices and put them in danger.

The young borrowers have begged their parents to stop using caps and punctuation.

Change the input text s to new borrower speak. Help save the next generation!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
borrow(char *s)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (!ispunct(s[i]) && !isspace(s[i]))
			s[j++] = tolower(s[i]);
	}
	s[j] = '\0';

	return s;
}

void
test(const char *s, const char *r)
{
	char b[128];

	strcpy(b, s);
	borrow(b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("WhAt! FiCK! DaMn CAke?", "whatfickdamncake");
	test("THE big PeOpLE Here!!", "thebigpeoplehere");
	test("i AM a TINY BoY!!", "iamatinyboy");
	return 0;
}
