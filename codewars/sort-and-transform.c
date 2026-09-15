/*

Given an array of numbers, return a string made up of four parts:

a four character 'word', made up of the characters derived from the first two and last two numbers in the array. order should be as read left to right (first, second, second last, last),

the same as above, post sorting the array into ascending order,

the same as above, post sorting the array into descending order,

the same as above, post converting the array into ASCII characters and sorting alphabetically.

The four parts should form a single string, each part separated by a hyphen (-).

Example format of solution: "asdf-tyui-ujng-wedg"

Examples
[111, 112, 113, 114, 115, 113, 114, 110]  -->  "oprn-nors-sron-nors"
[66, 101, 55, 111, 113]                   -->  "Beoq-7Boq-qoB7-7Boq"
[99, 98, 97, 96, 81, 82, 82]              -->  "cbRR-QRbc-cbRQ-QRbc"

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

int
cmp(const void *a, const void *b)
{
	int x, y;

	x = *(int *)a;
	y = *(int *)b;
	if (x < y)
		return -1;
	if (x == y)
		return 0;
	return 1;
}

char *
sortxfm(int *a, size_t n, char *b)
{
	char *p;

	*b = '\0';
	if (n < 4)
		return b;

	p = b;
	p += sprintf(p, "%c%c%c%c-", a[0], a[1], a[n - 2], a[n - 1]);
	qsort(a, n, sizeof(*a), cmp);
	p += sprintf(p, "%c%c%c%c-", a[0], a[1], a[n - 2], a[n - 1]);
	p += sprintf(p, "%c%c%c%c-", a[n - 1], a[n - 2], a[1], a[0]);
	p += sprintf(p, "%c%c%c%c", a[0], a[1], a[n - 2], a[n - 1]);
	return b;
}

void
test(int *a, size_t n, const char *r)
{
	char b[128];

	sortxfm(a, n, b);
	puts(b);
	assert(!strcmp(b, r));
}

int
main()
{
	int a1[] = { 111, 112, 113, 114, 115, 113, 114, 110 };
	int a2[] = { 66, 101, 55, 111, 113 };
	int a3[] = { 99, 98, 97, 96, 81, 82, 82 };

	test(a1, nelem(a1), "oprn-nors-sron-nors");
	test(a2, nelem(a2), "Beoq-7Boq-qoB7-7Boq");
	test(a3, nelem(a3), "cbRR-QRbc-cbRQ-QRbc");

	return 0;
}
