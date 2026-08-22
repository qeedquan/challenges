/*

Find the longest run of true in a list of booleans. Return the same list, with all other trues falsified.

Input, output
A list; any usual format (e.g., a delimited list as a string).

Details
True and false can be anything your language typically uses for those values, or the integers 1 and 0. If you use single characters, the list can be a concatenation (e.g., 10001).

If there's a tie for longest run, keep all tying runs true, and falsify all shorter runs.

Examples
input ↦ output
1,0,1,0,1 ↦ 1,0,1,0,1
1,1,0,1,1,0,1 ↦ 1,1,0,1,1,0,0
1,1,0,1,1,1,0,1,1 ↦ 0,0,0,1,1,1,0,0,0
1,1,1 ↦ 1,1,1
0,0,1 ↦ 0,0,1
0,0 ↦ 0,0
1,1,1,0,0,0,1,1,1,1,0,1,0,0,1,1,0,1,1,1,1,0,0,1,0 ↦ 0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0

(directly from https://stackoverflow.com/q/37447114)

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))
#define max(a, b) (((a) > (b)) ? (a) : (b))

void
print(int *a, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void
iterate(int *a, size_t n, void (*f)(int *, size_t, void *), void *ud)
{
	size_t i, l;

	for (i = 0; i < n; i++) {
		if (!a[i])
			continue;

		for (l = 0; i < n && a[i]; i++)
			l++;

		f(a + i - l, l, ud);
	}
}

void
maxones(int *, size_t l, void *ud)
{
	size_t *m;

	m = ud;
	*m = max(*m, l);
}

void
zeroize(int *a, size_t l, void *ud)
{
	size_t *m;

	m = ud;
	if (*m > l)
		memset(a, 0, l * sizeof(*a));
}

void
falsify(int *a, size_t n)
{
	size_t m;

	iterate(a, n, maxones, &m);
	iterate(a, n, zeroize, &m);
}

void
test(int *a, size_t n, int *r)
{
	falsify(a, n);
	print(a, n);
	assert(!memcmp(a, r, sizeof(*r) * n));
}

int
main(void)
{
	int a1[] = {1, 0, 1, 0, 1};
	int r1[] = {1, 0, 1, 0, 1};

	int a2[] = {1, 1, 0, 1, 1, 0, 1};
	int r2[] = {1, 1, 0, 1, 1, 0, 0};

	int a3[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
	int r3[] = {0, 0, 0, 1, 1, 1, 0, 0, 0};

	int a4[] = {1, 1, 1};
	int r4[] = {1, 1, 1};

	int a5[] = {0, 0, 1};
	int r5[] = {0, 0, 1};

	int a6[] = {0, 0};
	int r6[] = {0, 0};

	int a7[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0};
	int r7[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};

	test(a1, nelem(a1), r1);
	test(a2, nelem(a2), r2);
	test(a3, nelem(a3), r3);
	test(a4, nelem(a4), r4);
	test(a5, nelem(a5), r5);
	test(a6, nelem(a6), r6);
	test(a7, nelem(a7), r7);

	return 0;
}
