/*

Generators can be used to wonderful things. You can use them for numerous things, but here is one specific example. You are studying for a test so you must practice your multiplication, but you don't have a multiplication table showing the different examples. You have decided to create a generator that prints out a limitless list of time tables.

## Task

Your generator must take one parameter a then every time the generator is called you must return a string in the format of: 'a x b = c' where c is the answer. Also, the value of b, which starts at 1, must increment by 1 each time!

*/

#include <stdio.h>

typedef struct {
	int a;
	int x;
} Gen;

void
gennew(Gen *g, int a)
{
	g->a = a;
	g->x = 1;
}

char *
gennext(Gen *g, char *b)
{
	sprintf(b, "%d x %d = %d", g->a, g->x, g->a * g->x);
	g->x++;
	return b;
}

int
main()
{
	Gen g[1];
	char b[32];
	int i;

	gennew(g, 1);
	for (i = 0; i < 5; i++)
		printf("%s\n", gennext(g, b));

	return 0;
}
