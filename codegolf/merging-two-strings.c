/*

Introduction
Let's say that S1 = a...b and S2 = ..c... If we place them on top of each other, we get:

a...b
..c..
We merge both strings, with the . as the liquid character (which can overlapped). We get this:

a.c.b
If one of the string is longer than the other, we just apply the same algorithm:

a.....b
..c..

becomes:

a.c...b
and

a.....b
..c.......

becomes:

a.c...b...
If two characters collide, we just use the bottom character, e.g.

a..b
...c

becomes:

a..c
The Task
Given two non-empty strings, output the merged string. Note, you can assume that the input only contains periods and lowercase letters (or uppercase letters if that is more convenient).

Test cases
Input              Output
a....b ..c...      a.c..b
aaaaaa bbbbbb      bbbbbb
ab.ab. b.b.b.      bbbab.
a.......b c        c.......b

This is code-golf, so the submission with the least amount of bytes wins!

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
merge(const char *s, const char *t, char *b)
{
	size_t i, j, k;

	for (i = j = k = 0; s[i] || t[j];) {
		if (!s[i])
			b[k++] = t[j];
		else if (!t[j])
			b[k++] = s[i];
		else if (s[i] == '.' || t[j] != '.')
			b[k++] = t[j];
		else
			b[k++] = s[j];

		if (s[i])
			i++;
		if (t[j])
			j++;
	}
	b[k] = '\0';

	return b;
}

void
test(const char *s, const char *t, const char *r)
{
	char b[128];

	merge(s, t, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("a...b", "..c..", "a.c.b");
	test("a....b", "..c...", "a.c..b");
	test("aaaaaa", "bbbbbb", "bbbbbb");
	test("ab.ab.", "b.b.b.", "bbbab.");
	test("a.......b", "c", "c.......b");

	return 0;
}
