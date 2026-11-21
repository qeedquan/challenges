/*

Given two arrays a and b write a function comp(a, b) (orcompSame(a, b)) that checks whether the two arrays have the "same" elements, with the same multiplicities. "Same" means, here, that the elements in b are the elements in a squared, regardless of the order.

Examples
Valid arrays
a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [121, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a, b) returns true because in b 121 is the square of 11, 14641 is the square of 121, 20736 the square of 144, 361 the square of 19, 25921 the square of 161, and so on. It gets obvious if we write b's elements in terms of squares:

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19]
Invalid arrays
If, for example, we change the first number to something else, comp may not return true anymore:

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [132, 14641, 20736, 361, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 132 is not the square of any number of a.

a = [121, 144, 19, 161, 19, 144, 19, 11]
b = [121, 14641, 20736, 36100, 25921, 361, 20736, 361]
comp(a,b) returns false because in b 36100 is not the square of any number of a.

Remarks
a or b might be [] or {} (all languages except R, Shell).
a or b might be nil or null or None or nothing (except in C++, Crystal, Dart, Elixir, Fortran, F#, Haskell, Nim, OCaml, Pascal, Perl, PowerShell, Prolog, PureScript, R, Racket, Rust, Shell, Swift).
If a or b are nil (or null or None, depending on the language), the problem doesn't make sense so return false.

Note for C
The two arrays have the same size (> 0) given as parameter in function comp.

*/

#include <assert.h>
#include <stdlib.h>

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

bool
comp(int *a, int *b, size_t n)
{
	size_t i;
	int f;

	if (!a || !b || !n)
		return false;

	qsort(a, n, sizeof(*a), cmp);
	qsort(b, n, sizeof(*b), cmp);

	f = 0x3;
	for (i = 0; i < n && f; i++) {
		if (a[i] * a[i] != b[i])
			f &= ~0x1;
		if (b[i] * b[i] != a[i])
			f &= ~0x2;
	}
	return f != 0;
}

int
main()
{
	int a1[] = { 121, 144, 19, 161, 19, 144, 19, 11 };
	int a2[] = { 121, 144, 19, 161, 19, 144, 19, 11 };
	int a3[] = { 121, 144, 19, 161, 19, 144, 19, 11 };

	int b1[] = { 121, 14641, 20736, 361, 25921, 361, 20736, 361 };
	int b2[] = { 132, 14641, 20736, 361, 25921, 361, 20736, 361 };
	int b3[] = { 121, 14641, 20736, 36100, 25921, 361, 20736, 361 };

	assert(comp(a1, b1, nelem(a1)) == true);
	assert(comp(a2, b2, nelem(a2)) == false);
	assert(comp(a3, b3, nelem(a3)) == false);
	assert(comp(NULL, b3, nelem(a3)) == false);
	assert(comp(a3, NULL, nelem(a3)) == false);

	return 0;
}
