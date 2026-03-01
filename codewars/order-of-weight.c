/*

Given an array of strings, sort the array into order of weight from light to heavy.

Weight units are grams(G), kilo-grams(KG) and tonnes(T).

Arrays will always contain correct and positive values aswell as uppercase letters.

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

double
value(const char *s)
{
	double w;
	char u[4];

	if (sscanf(s, "%lf%3s", &w, u) != 2)
		return 0;
	if (!strcmp(u, "KG"))
		w *= 1000;
	else if (!strcmp(u, "T"))
		w *= 907184.74;
	return w;
}

int
cmp(const void *a, const void *b)
{
	const char *s, *t;
	double x, y;

	s = *(const char **)a;
	t = *(const char **)b;
	x = value(s);
	y = value(t);
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

void
arrange(const char **s, size_t n)
{
	qsort(s, n, sizeof(*s), cmp);
}

void
test(const char **s, size_t n, const char **r)
{
	size_t i;

	arrange(s, n);
	for (i = 0; i < n; i++)
		assert(!strcmp(s[i], r[i]));
}

int
main()
{
	const char *s1[] = {"200G", "300G", "150G", "100KG"};
	const char *s2[] = {"400G", "100T", "150KG", "100G"};
	const char *s3[] = {"4T", "300G", "450G", "900KG"};
	const char *s4[] = {"400T", "100T", "1T", "100G"};
	const char *s5[] = {"1G", "2KG", "3T", "100KG"};
	const char *s6[] = {"100KG", "100G", "150T", "150KG"};

	const char *r1[] = {"150G", "200G", "300G", "100KG"};
	const char *r2[] = {"100G", "400G", "150KG", "100T"};
	const char *r3[] = {"300G", "450G", "900KG", "4T"};
	const char *r4[] = {"100G", "1T", "100T", "400T"};
	const char *r5[] = {"1G", "2KG", "100KG", "3T"};
	const char *r6[] = {"100G", "100KG", "150KG", "150T"};

	test(s1, nelem(s1), r1);
	test(s2, nelem(s2), r2);
	test(s3, nelem(s3), r3);
	test(s4, nelem(s4), r4);
	test(s5, nelem(s5), r5);
	test(s6, nelem(s6), r6);

	return 0;
}
