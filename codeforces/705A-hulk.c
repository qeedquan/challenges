/*

Dr. Bruce Banner hates his enemies (like others don't). As we all know, he can barely talk when he turns into the incredible Hulk. That's why he asked you to help him to express his feelings.

Hulk likes the Inception so much, and like that his feelings are complicated. They have n layers. The first layer is hate, second one is love, third one is hate and so on...

For example if n = 1, then his feeling is "I hate it" or if n = 2 it's "I hate that I love it", and if n = 3 it's "I hate that I love that I hate it" and so on.

Please help Dr. Banner.

Input
The only line of the input contains a single integer n (1 ≤ n ≤ 100) — the number of layers of love and hate.

Output
Print Dr.Banner's feeling in one line.

Examples
input
1
output
I hate it

input
2
output
I hate that I love it

input
3
output
I hate that I love that I hate it

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

char *
gen(int n, char *b)
{
	int i, l;

	if (n < 1) {
		*b = '\0';
		return b;
	}

	l = sprintf(b, "I");
	for (i = 0; i < n; i++) {
		if ((i & 1) == 0)
			l += sprintf(b + l, " hate ");
		else
			l += sprintf(b + l, " love ");
		if (i + 1 < n)
			l += sprintf(b + l, "that I");
	}
	l += sprintf(b + l, "it");
	return b;
}

void
test(int n, const char *r)
{
	char b[128];

	gen(n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test(1, "I hate it");
	test(2, "I hate that I love it");
	test(3, "I hate that I love that I hate it");
	test(4, "I hate that I love that I hate that I love it");

	return 0;
}
