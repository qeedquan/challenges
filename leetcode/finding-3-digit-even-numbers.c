/*

You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

    The integer consists of the concatenation of three elements from digits in any arbitrary order.
    The integer does not have leading zeros.
    The integer is even.

For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array.
Notice that there are no odd integers or integers with leading zeros.

Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits.
In this example, the digit 8 is used twice each time in 288, 828, and 882.

Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.

Constraints:

    3 <= digits.length <= 100
    0 <= digits[i] <= 9

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long ulong;

int
snprint(char *str, size_t size, const char *fmt, ...)
{
	va_list ap;
	size_t n;

	va_start(ap, fmt);
	n = vsnprintf(str, size, fmt, ap);
	va_end(ap);
	return (size < n) ? size : n;
}

void
dump(ulong *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%lu ", a[i]);
	printf("\n");
}

ulong
combine(ulong *a, ulong *d, size_t n)
{
	char b[sizeof(*a) * CHAR_BIT];
	size_t i, l;

	for (i = 0; i < n; i++) {
		if (a[d[i]])
			break;

		return 0;
	}

	l = 0;
	for (i = 0; i < n; i++)
		l += snprintf(b + l, sizeof(b) - l, "%lu", a[d[i]]);
	return strtoul(b, NULL, 10);
}

size_t
dedup(ulong *a, size_t n)
{
	size_t i, j;

	for (i = j = 0; i < n; i++) {
		a[j++] = a[i];
		while (i < n && a[i] == a[i + 1])
			i++;
	}
	return j;
}

int
cmp(const void *a, const void *b)
{
	ulong x, y;

	x = *(ulong *)a;
	y = *(ulong *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

size_t
evens(ulong *a, size_t n, ulong *r)
{
	size_t d[3], l;
	ulong v;

	l = 0;
	for (d[0] = 0; d[0] < n; d[0]++) {
		for (d[1] = 0; d[1] < n; d[1]++) {
			for (d[2] = 0; d[2] < n; d[2]++) {
				if (d[0] != d[1] && d[1] != d[2] && d[0] != d[2]) {
					v = combine(a, d, nelem(d));
					if (v > 0 && ((v & 1) == 0))
						r[l++] = v;
				}
			}
		}
	}
	qsort(r, l, sizeof(*r), cmp);
	return dedup(r, l);
}

void
test(ulong *a, size_t n, ulong *r, size_t nr)
{
	ulong p[128];
	size_t np;

	np = evens(a, n, p);
	dump(p, np);
	assert(np == nr);
	if (r)
		assert(!memcmp(p, r, sizeof(*r) * nr));
}

int
main(void)
{
	ulong a1[] = { 2, 1, 3, 0 };
	ulong r1[] = { 102, 120, 130, 132, 210, 230, 302, 310, 312, 320 };

	ulong a2[] = { 2, 2, 8, 8, 2 };
	ulong r2[] = { 222, 228, 282, 288, 822, 828, 882 };

	ulong a3[] = { 3, 7, 5 };

	ulong a4[] = { 1, 2, 3 };
	ulong r4[] = { 132, 312 };

	test(a1, nelem(a1), r1, nelem(r1));
	test(a2, nelem(a2), r2, nelem(r2));
	test(a3, nelem(a3), NULL, 0);
	test(a4, nelem(a4), r4, nelem(r4));

	return 0;
}
