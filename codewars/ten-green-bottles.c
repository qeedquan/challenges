/*

Who knows the nursery rhyme Ten Green Bottles ( https://www.youtube.com/watch?v=Ak7kedzR8bg )?

Lyrics:

Ten green bottles hanging on the wall,
Ten green bottles hanging on the wall,
And if one green bottle should accidentally fall,
There'll be nine green bottles hanging on the wall.

Nine green bottles hanging on the wall,
Nine green bottles hanging on the wall,
And if one green bottle should accidentally fall,
There'll be eight green bottles hanging on the wall.

Eight green bottles hanging on the wall...
Seven green bottles hanging on the wall...
...

One green bottle hanging on the wall,
One green bottle hanging on the wall,
If that one green bottle should accidentally fall,
There'll be no green bottles hanging on the wall.

Task
Write some amazing code to reproduce the above lyrics starting from n green bottles!

parameter n is 1 to 10
newline terminates every line (including the last)
don't forget the blank lines between the verses

*/

#include <stdio.h>
#include <ctype.h>

void
tgb(int n)
{
	static const char *tab[] = {
		"no",
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
	};

	const char *s;
	int i;

	if (n < 1 || n > 10)
		return;

	for (i = n; i > 0; i--) {
		s = (i > 1) ? "s" : "";
		printf("%s green bottle%s hanging on the wall,\n", tab[i], s);
		printf("%s green bottle%s hanging on the wall,\n", tab[i], s);
		printf("And if one green bottle should accidentally fall,\n");
		printf("There'll be %c%s green bottles hanging on the wall.\n", tolower(tab[i - 1][0]), tab[i - 1] + 1);
		printf("\n");
	}
}

int
main()
{
	tgb(10);
	return 0;
}
