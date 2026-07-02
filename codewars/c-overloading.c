/*

You have to write a function called add, which supports the following prototypes:

// returns a + b
int add (int a, int b);
// concatenates a to the left of b, and returns b
char *add (int a, char *b);
// concatenates b to the right of a, and returns a
char *add (char *a, int b);
// concatenates b to the right of a, and returns a
char *add (char *a, const char *b);
Due to the way your code is compiled, your function(s ?) must be static.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define add(a, b) _Generic((a), int: _Generic((b), int: addi, char *: addis), char *: _Generic((b), int: addsi, char *: adds))(a, b)

static int
addi(int a, int b)
{
	return a + b;
}

static char *
addis(int a, char *b)
{
	size_t n, m;

	n = snprintf(NULL, 0, "%d", a);
	m = strlen(b);
	memmove(b + n + 1, b, m + 1);
	sprintf(b, "%d", a);
	memmove(b + n, b + n + 1, m + 1);
	return b;
}

static char *
addsi(char *a, int b)
{
	size_t n;

	n = strlen(a);
	sprintf(a + n, "%d", b);
	return a;
}

static char *
adds(char *a, const char *b)
{
	size_t n;

	n = strlen(a);
	sprintf(a + n, "%s", b);
	return a;
}

int
main()
{
	char b[128] = "hello";

	printf("%d\n", add(20, 30));
	add(-334854, b);
	add(b, 2945);
	add(b, "ZXX");
	puts(b);

	return 0;
}
