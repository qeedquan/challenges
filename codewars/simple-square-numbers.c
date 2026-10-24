/*

In this Kata, you will be given a number n (n > 0) and your task will be to return the smallest square number N (N > 0) such that n + N is also a perfect square. If there is no answer, return -1 (nil in Clojure, Nothing in Haskell, None in Rust).

solve(13) = 36
//because 36 is the smallest perfect square that can be added to 13 to form a perfect square => 13 + 36 = 49

solve(3) = 1 // 3 + 1 = 4, a perfect square
solve(12) = 4 // 12 + 4 = 16, a perfect square
solve(9) = 16
solve(4) = -1
More examples in test cases.

Good luck!

*/

#include <assert.h>
#include <stdio.h>
#include <math.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A024352
// https://oeis.org/A129861 (related)
long
solve(long n)
{
	long i, s, x;

	if (n < 1)
		return -1;

	for (i = 1; i < n; i++) {
		x = n + (i * i);
		s = sqrt(x);
		if (s * s == x)
			return i * i;
	}
	return -1;
}

int
main()
{
	static const long tab[] = {
		3, 5, 7, 8, 9, 11, 12, 13, 15, 16, 17, 19, 20, 21, 23, 24, 25, 27, 28,
		29, 31, 32, 33, 35, 36, 37, 39, 40, 41, 43, 44, 45, 47, 48, 49, 51,
		52, 53, 55, 56, 57, 59, 60, 61, 63, 64, 65, 67, 68, 69, 71, 72, 73,
		75, 76, 77, 79, 80, 81, 83, 84, 85, 87, 88, 89, 91, 92, 93, 95, 96
	};

	size_t n;
	long i;

	for (i = n = 0; n < nelem(tab); i++) {
		if (solve(i) != -1)
			assert(i == tab[n++]);
	}

	assert(solve(3) == 1);
	assert(solve(13) == 36);
	assert(solve(9) == 16);
	assert(solve(4) == -1);
	assert(solve(5) == 4);
	assert(solve(7) == 9);
	assert(solve(8) == 1);
	assert(solve(9) == 16);
	assert(solve(10) == -1);
	assert(solve(11) == 25);
	assert(solve(13) == 36);
	assert(solve(17) == 64);
	assert(solve(88901) == 5428900);
	assert(solve(290101) == 429235524);

	return 0;
}
