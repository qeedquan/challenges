/*

Description

The company Al's Chocolate Mangos has a web site where visitors can guess how many chocolate covered mangos are in a virtual jar. Visitors type in a guess between 1 and 99 and then click on a "Submit" button. Unfortunately, the response time from the server is often long, and visitors get impatient and click "Submit" several times in a row. This generates many duplicate requests.
Your task is to write a program to assist the staff at ACM in filtering out these duplicate requests.

Input

The input consists of a series of lines, one for each web session. The first integer on a line is N, 0 < N ≤ 25, which is the number of guesses on this line. These guesses are all between 1 and 99, inclusive. The value N = 0 indicates the end of all the input.

Output

For each input data set, output a single line with the guesses in the original order, but with consecutive duplicates removed. Conclude each output line with the dollar sign character '$'. Note that there is a single space between the last integer and the dollar sign.

Sample Input

5 1 22 22 22 3
4 98 76 20 76
6 19 19 35 86 86 86
1 7
0

Sample Output

1 22 3 $
98 76 20 76 $
19 35 86 $
7 $

Source

Mid-Central USA 2009

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

char *
undup(int *a, size_t n, char *b)
{
	size_t i, l;
	int v;

	l = 0;
	v = 0;
	for (i = 0; i < n; i++) {
		if (i == 0 || v != a[i]) {
			l += sprintf(b + l, "%d ", a[i]);
			v = a[i];
		}
	}
	sprintf(b + l, "$");
	return 0;
}

void
test(int *a, size_t n, const char *r)
{
	char b[128];

	undup(a, n, b);
	printf("%s\n", b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	int a1[] = {1, 22, 22, 22, 3};
	int a2[] = {98, 76, 20, 76};
	int a3[] = {19, 19, 35, 86, 86, 86};
	int a4[] = {7};

	test(a1, nelem(a1), "1 22 3 $");
	test(a2, nelem(a2), "98 76 20 76 $");
	test(a3, nelem(a3), "19 35 86 $");
	test(a4, nelem(a4), "7 $");

	return 0;
}
