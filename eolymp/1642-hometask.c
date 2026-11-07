/*

Kolya is still trying to pass a test in Number Theory.
The lecturer has become so desperate about Kolya's knowledge that she gives him the same problem every time.

The problem is to check whether n! is divisible by n^2.

Input
One integer n (1≤n≤10^9).

Output
Print YES if n! is divisible by n^2, otherwise print NO.

Examples
Input #1
3

Answer #1
NO

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef long long vlong;

// https://oeis.org/A056653
const char *
solve(vlong n)
{
	vlong i, s;

	if (n < 1 || n == 2 || n == 3 || n == 4)
		return "NO";
	if (n == 1)
		return "YES";

	s = sqrt(n);
	for (i = 2; i <= s; i++) {
		if (!(n % i))
			return "YES";
	}
	return "NO";
}

void
test(vlong n, const char *r)
{
	assert(!strcmp(solve(n), r));
}

int
main()
{
	static const vlong tab[] = {
		1, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28,
		30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 49, 50, 51,
		52, 54, 55, 56, 57, 58, 60, 62, 63, 64, 65, 66, 68, 69, 70, 72, 74,
		75, 76, 77, 78, 80, 81, 82, 84, 85, 86, 87, 88, 90, 91, 92, 93, 94,
		95
	};

	size_t i;
	vlong n;

	test(3, "NO");

	n = 0;
	for (i = 0; i < nelem(tab); n++) {
		if (n == tab[i]) {
			test(n, "YES");
			i += 1;
		} else
			test(n, "NO");
	}
	return 0;
}
