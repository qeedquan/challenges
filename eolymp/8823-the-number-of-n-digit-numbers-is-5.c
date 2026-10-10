/*

The program takes a natural number n as input.It should output the count of n-digit natural numbers that include at least one digit 7.

Input
A natural number n.

Output
The solution to the problem.

Examples

Input #1
1

Answer #1
1

Input #2
2

Answer #2
18

*/

#include <assert.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

typedef unsigned long long uvlong;

// https://oeis.org/A088924
uvlong
solve(uvlong n)
{
	if (n < 1)
		return 0;
	return powl(10, n) - powl(10, n - 1) - (8 * powl(9, n - 1));
}

int
main()
{
	static const uvlong tab[] = {
		1,
		18,
		252,
		3168,
		37512,
		427608,
		4748472,
		51736248,
		555626232,
		5900636088,
		62105724792,
		648951523128,
		6740563708152,
		69665073373368,
		716985660360312,
		7352870943242808,
		75175838489185272,
		766582546402667448,
	};

	uvlong i;

	assert(solve(1) == 1);
	assert(solve(2) == 18);

	for (i = 0; i < nelem(tab); i++)
		assert(solve(i + 1) == tab[i]);

	return 0;
}
