/*

Well... there are 59 (now 60) questions tagged sorting, but no simple quicksorts.

That must be fixed.

For those unfamiliar with quicksort, here is a breakdown, courtesy of Wikipedia-

Pick an element, called a pivot, from the array.
Reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.
Rules
The rules are simple:

Implement a numerical quicksort in the programming language of your choice.
The pivot should be chosen at random or with median of three (1st, last, and middle element).
Your program can be a complete program or function.
You can get the input using STDIN, command line args, or function parameters. If using a string input, the input is space separated.
The input may contain decimal and negative values. However, there will be no duplicates.
You may output to STDOUT or by returning from the function.
No built-in sorting (or sorting related) functions or standard loopholes.
The list may be an arbitrary length.
Bonus #1: On lists or sub-lists of length <= 5, use insertion sort to speed things up a bit. Reward: -15%.

Bonus #2: If your language supports concurrency, sort the list in parallel. If you are using an insertion sort on sub-lists, the final insertion sort doesn't need to be in parallel. Built in thread pools/ thread scheduling are allowed. Reward: -15%.

Note: Median of three was confusing some people, so here is an explanation, courtesy of (again) Wikipedia:

choosing the median of the first, middle and last element of the partition for the pivot

Scoring
This is code-golf. Base score is in bytes. If you got one bonus, take 15% off that number. If you got both, take 30% off. That really sounds like a sales pitch.

This isn't about finding the shortest answer overall, but rather the shortest in each language.

And now, a shameless copy of the leaderboard snippet.

*/

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// https://research.swtch.com/qsort
// https://www.cs.dartmouth.edu/~doug/aqsort.c
typedef struct {
	int *val;
	int ncmp;
	int nsolid;
	int candidate;
	int gas;
} Adversary;

void *
xcalloc(size_t nmemb, size_t size)
{
	void *p;

	if (nmemb == 0)
		nmemb = 1;
	if (size == 0)
		size = 1;

	p = calloc(nmemb, size);
	if (!p)
		abort();
	return p;
}

int
cmp(const void *a, const void *b, void *ud)
{
	Adversary *p;
	int x, y;

	p = ud;
	x = *(int *)a;
	y = *(int *)b;

	p->ncmp++;
	if (p->val[x] == p->gas && p->val[y] == p->gas) {
		if (x == p->candidate)
			p->val[x] = p->nsolid++;
		else
			p->val[y] = p->nsolid++;
	}
	if (p->val[x] == p->gas)
		p->candidate = x;
	else if (p->val[y] == p->gas)
		p->candidate = y;

	if (p->val[x] < p->val[y])
		return -1;
	if (p->val[x] == p->val[y])
		return 0;
	return 1;
}

int
aqsort(int n, int *a)
{
	Adversary p[1];
	int i, *v;

	memset(p, 0, sizeof(*p));
	p->val = a;
	p->gas = n - 1;

	v = xcalloc(n, sizeof(*v));
	for (i = 0; i < n; i++) {
		v[i] = i;
		p->val[i] = p->gas;
	}
	qsort_r(v, n, sizeof(*v), cmp, p);

	for (i = 1; i < n; i++)
		assert(p->val[v[i]] == p->val[v[i - 1]] + 1);

	free(v);
	return p->ncmp;
}

void
usage(void)
{
	fprintf(stderr, "usage: n\n");
	exit(2);
}

int
bench(int n)
{
	int *b, i;

	b = xcalloc(n, sizeof(*b));
	i = aqsort(n, b);
	free(b);
	return i;
}

int
main(int argc, char *argv[])
{
	int n;

	if (argc < 2)
		usage();

	n = atoi(argv[1]);
	printf("%d %d\n", n, bench(n));
	return 0;
}
