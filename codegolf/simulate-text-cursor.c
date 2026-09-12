/*

You are given a string [A-Za-z|]+ that contains exactly one occurrence of | denoting the current position of the cursor and a sequence of moves [><#]+ where:

>: moves the cursor one position to the right
<: moves the cursor one position to the left
#: moves the cursor one position to the left, deletes the character to its right and shifts back any text after (simulates a backspace)
If the cursor is the first character of the string, moving left (<) or deleting (#) should keep the string unchanged. Similarly, if the cursor is the last character of the string, moving right (>) should keep the string unchanged.

Your goal is to simulate the sequence of moves on the provided string.

Test cases
String	Moves	Expected result
This is a test|	#<<<<<######>	Tha| tes
Curs|or end test	>>>>>>>>>>>>><>	Cursor end test|
Cursor s|tart test	<<<<<<<<<<<><	|Cursor start test
Delete all|	##############><<<	|
|	>><##>	|
Steps for the 1st test case
Input: This is a test|
Moves: #<<<<<######>
Steps:

Move	String
This is a test|   (Input)
(#)	This is a tes|
(<)	This is a te|s
(<)	This is a t|es
(<)	This is a |tes
(<)	This is a| tes
(<)	This is |a tes
(#)	This is|a tes
(#)	This i|a tes
(#)	This |a tes
(#)	This|a tes
(#)	Thi|a tes
(#)	Th|a tes
(>)	Tha| tes   (Output)
If you want to see the intermediate steps for the other test cases you can check this spreadsheet. If you want to run the simulation on your own inputs, you can make a copy of the spreadsheet and change the corresponding fields in the 'simulator' tab.

This is code-golf so shortest answer in bytes wins.

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *
marks(const char *s, size_t *n, size_t *d)
{
	size_t i, l;
	char *p, *t;

	l = strlen(s);
	p = calloc(l, sizeof(*p));
	if (!p)
		return NULL;

	i = 0;
	t = strchr(s, '|');
	if (t) {
		i = t - s;
		p[i] = 1;
	}

	*n = l;
	*d = i;
	return p;
}

void
cons(const char *s, char *b, char *p, size_t d, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		if (i == d)
			b[j++] = '|';
		if (!p[i])
			b[j++] = s[i];
	}
	if (i == d)
		b[j++] = '|';
	b[j] = '\0';
}

size_t
right(char *p, size_t d, size_t n)
{
	while (d < n) {
		d++;
		if (d < n && !p[d])
			break;
	}
	return d;
}

size_t
left(char *p, size_t d)
{
	while (d) {
		d--;
		if (d && !p[d])
			break;
	}
	return d;
}

size_t
del(char *p, size_t d, size_t n)
{
	while (d && p[d - 1])
		d--;

	if (d)
		p[--d] = 1;

	while (d < n && p[d])
		d++;

	return d;
}

char *
sim(const char *s, const char *m, char *b)
{
	size_t d, i, n;
	char *p;

	p = marks(s, &n, &d);
	if (!p)
		return NULL;

	for (i = 0; m[i]; i++) {
		switch (m[i]) {
		case '>':
			d = right(p, d, n);
			break;
		case '<':
			d = left(p, d);
			break;
		case '#':
			d = del(p, d, n);
			break;
		}
	}

	cons(s, b, p, d, n);
	free(p);
	return b;
}

void
test(const char *s, const char *m, const char *r)
{
	char b[128];

	assert(sim(s, m, b));
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main()
{
	test("This is a test|", "#<<<<<######>", "Tha| tes");
	test("Curs|or end test", ">>>>>>>>>>>>><>", "Cursor end test|");
	test("Cursor s|tart test", "<<<<<<<<<<<><", "|Cursor start test");
	test("Delete all|", "	##############><<<", "|");
	test("|", ">><##>", "|");
	test("abc|", "<<#>", "b|c");
	test("123|456", ">>><<", "123|456");
	test("xyz|abc", "", "xyz|abc");
	test("|", "<><><><><><><>>><<<>>", "|");
	test("animat|s", "<<<", "ani|mats");
	test("abbbbbbbbbc|", "###################################", "|");

	return 0;
}
