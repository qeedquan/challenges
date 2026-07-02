/*

Write a function mapEmUp that conditionally maps an array of inputs according to a set of supplied conditions. The function takes in two arguments:

An array of inputs
An array of key-value pairs of predicates and mappers

For example:

mapEmUp([1, 2, 3], [
                    [ function (i) { return i>2; },
                    function (i) { return i; }],
                    [ function (i) { return i<2; },
                    function () { return 0; }]
                  ]);

returns

[0, -1, 3]

Each item in the second argument array is an array itself, where the first element is a predicate and the second element is a mapper. The function mapEmUp should pick up each item from the supplied array and run it against each item in the second argument. Where a predicate turns out to be true, the corresponding mapper is applied. Note that the search only continues until a match is found. When there is no predicate matching a specific input, return -1;

*/

#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef bool (*predfn)(int);
typedef int (*mapfn)(int);

void
mapemup(int *a, size_t n, predfn *p, mapfn *f, size_t m)
{
	size_t i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (p[j](a[i])) {
				a[i] = f[j](a[i]);
				break;
			}
		}
		if (j == m)
			a[i] = -1;
	}
}

bool
gt2(int x)
{
	return x > 2;
}

bool
lt2(int x)
{
	return x < 2;
}

int
id(int x)
{
	return x;
}

int
zero(int)
{
	return 0;
}

int
main()
{
	int a[] = {1, 2, 3};
	predfn p[] = {gt2, lt2};
	mapfn f[] = {id, zero};

	mapemup(a, nelem(a), p, f, nelem(p));
	printf("%d %d %d\n", a[0], a[1], a[2]);
	return 0;
}
