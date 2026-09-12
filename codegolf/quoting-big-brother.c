/*

Task: Have your program randomly choose one of the following two quotes at runtime and print that one quote, exactly as shown.

1:

Under the spreading chestnut tree
I sold you and you sold me.
There lie they, and here lie we
Under the spreading chestnut tree.
2:

WAR IS PEACE.
FREEDOM IS SLAVERY.
IGNORANCE IS STRENGTH.
Restrictions: The words spreading, chestnut, PEACE, FREEDOM, and STRENGTH must appear in your code. No word from the above two quotes may appear in your code more than once.

Shortest solution wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void
bigbro(void)
{
	static const char *quotes[2][5] = {
	    {
	        "Under the spreading chestnut tree",
	        "I sold you and you sold me.",
	        "There lie they, and here lie we",
	        "Under the spreading chestnut tree.",
	        NULL,
	    },

	    {
	        "WAR IS PEACE.",
	        "FREEDOM IS SLAVERY.",
	        "IGNORANCE IS STRENGTH.",
	        NULL,
	    },
	};

	const char **p;
	int i, n;

	n = rand() & 1;
	p = quotes[n];
	for (i = 0; p[i]; i++)
		puts(p[i]);
}

int
main(void)
{
	srand(time(NULL));
	bigbro();
	return 0;
}
