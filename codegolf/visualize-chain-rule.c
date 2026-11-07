/*

Definition
The chain rule with two functions state that:

D[f(g(x))] = f'(g(x)) * g'(x)
Or, alternatively:

D[f1(f2(x))] = f1'(f2(x)) * f2'(x)
The chain rule with three functions state that:

D[f(g(h(x)))] = f'(g(h(x))) * g'(h(x)) * h'(x)
Or, alternatively:

D[f1(f2(f3(x)))] = f1'(f2(f3(x))) * f2'(f3(x)) * f3'(x)
Et cetera.

Task
Given an integer between 2 and 21, output the chain rule with that many functions, either in the first form or in the second form.
Please specify if you are using the second form.
Specs
The format of the string must be exactly that stated above, with:
all the spaces kept intact
a capitalized D
a square bracket immediately following D
the asterisk kept intact
One extra trailing space (U+0020) is allowed.
Leading zeros in the function names in the second form (e.g. f01 instead of f1) is allowed.
Testcases
If you use the first form:

input output
2     D[f(g(x))] = f'(g(x)) * g'(x)
3     D[f(g(h(x)))] = f'(g(h(x))) * g'(h(x)) * h'(x)
If you use the second form:

input output
2     D[f1(f2(x))] = f1'(f2(x)) * f2'(x)
3     D[f1(f2(f3(x)))] = f1'(f2(f3(x))) * f2'(f3(x)) * f3'(x)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
chainrule(int n, char *b)
{
	size_t l;
	int i, j;

	if (n < 1) {
		sprintf(b, "D[]");
		return b;
	}

	l = 0;
	l += sprintf(b + l, "D[");
	for (i = 1; i <= n; i++)
		l += sprintf(b + l, "f%d(", i);
	l += sprintf(b + l, "x");
	for (i = 0; i < n; i++)
		l += sprintf(b + l, ")");
	l += sprintf(b + l, "] = ");

	for (i = 1; i <= n; i++) {
		l += sprintf(b + l, "f%d'(", i);
		for (j = i + 1; j <= n; j++)
			l += sprintf(b + l, "f%d(", j);

		l += sprintf(b + l, "x");
		for (j = 0; j <= n - i; j++)
			l += sprintf(b + l, ")");

		if (i != n)
			l += sprintf(b + l, " * ");
	}

	return b;
}

void
test(int n, const char *r)
{
	char b[256];

	chainrule(n, b);
	printf("%s\n%s\n\n", b, r);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "D[f1(x)] = f1'(x)");
	test(2, "D[f1(f2(x))] = f1'(f2(x)) * f2'(x)");
	test(3, "D[f1(f2(f3(x)))] = f1'(f2(f3(x))) * f2'(f3(x)) * f3'(x)");
	test(4, "D[f1(f2(f3(f4(x))))] = f1'(f2(f3(f4(x)))) * f2'(f3(f4(x))) * f3'(f4(x)) * f4'(x)");
	test(5, "D[f1(f2(f3(f4(f5(x)))))] = f1'(f2(f3(f4(f5(x))))) * f2'(f3(f4(f5(x)))) * f3'(f4(f5(x))) * f4'(f5(x)) * f5'(x)");
	test(6, "D[f1(f2(f3(f4(f5(f6(x))))))] = f1'(f2(f3(f4(f5(f6(x)))))) * f2'(f3(f4(f5(f6(x))))) * f3'(f4(f5(f6(x)))) * f4'(f5(f6(x))) * f5'(f6(x)) * f6'(x)");

	return 0;
}
