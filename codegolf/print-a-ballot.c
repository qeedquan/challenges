/*

As you all know, today is election day!

Your task today is to print out a ballot, given an input.

If the input is Hillary Clinton, print:

Hillary Clinton   ===-----===>
Donald Trump      ===     ===>
____________      ===     ===>
However, if the input is Donald Trump, print:

Hillary Clinton   ===     ===>
Donald Trump      ===-----===>
____________      ===     ===>
If it is something else, write it on the third line:

Hillary Clinton   ===     ===>
Donald Trump      ===     ===>
Oliver Ni         ===-----===>
(Technically, I'm not 18 yet...)

Remember, this is code-golf, so the code with the fewest bytes wins.

*/

#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

void
ballot(const char *s)
{
	const char *tab[] = {
	    "Hillary Clinton",
	    "Donald Trump",
	    "____________",
	};

	const char *s0, *s1;
	size_t i;
	int f;

	f = 0;
	for (i = 0; i < nelem(tab); i++) {
		s0 = tab[i];
		s1 = "     ";
		if (!strcmp(s, tab[i]) || (!f && i + 1 >= nelem(tab))) {
			s0 = s;
			s1 = "-----";
			f = 1;
		}

		printf("%-18s===%s===>\n", s0, s1);
	}
	printf("\n");
}

int
main()
{
	ballot("Hillary Clinton");
	ballot("Donald Trump");
	ballot("Oliver Ni");

	return 0;
}
