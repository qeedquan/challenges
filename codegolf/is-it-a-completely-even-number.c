/*

A completely even number is a positive even integer whose divisors (not including 1) are all even.

Some completely even numbers are:

2 (divisors: 2, 1)
4 (divisors: 4, 2, 1)
16 (divisors: 16, 8, 4, 2, 1)
128 (divisors: 128, 64, 32, 16, 8, 4, 2, 1).
Some non-completely even numbers are:

10 (divisors: 10, 5, 2, 1)
12 (divisors: 12, 6, 4, 3, 2, 1)
14 (divisors: 14, 7, 2, 1)
18 (divisors: 18, 9, 6, 3, 2, 1)
1, being odd, is not completely even.
0 is not completely even (it's divisible by all positive integers, including odd numbers) but you do not need to handle this.

Your challenge is to take a positive integer as input and output a truthy value if it is completely even and a falsy value if it is not. These outputs do not need to be consistent.

If your solution doesn't return a falsy value for 0, it's encouraged to show what changes would be necessary to make it do so. Especially encouraged is to show how your solution differs from checking if the input is a power of 2; in some languages it may be shorter, and in some longer.

Input may be taken via any allowed method, and output may be given via any allowed method.

The shortest code in bytes wins!

*/

#include <assert.h>
#include <stdbool.h>

/*

@Dennis:

How it works
If n = 0, then n ⊕ (n - 1) = 0 ⊕ -1 = -1 < 0 = n, so the function returns False.
If n = 1, then n ⊕ (n - 1) = 1 ⊕ 0 = 1 = n, so the function returns False.
If 2^k < n < 2^k+1, then 2^k ≤ n - 1 < 2^k+1, so n and n - 1 have the 2^k bit in common, n ⊕ (n - 1) < 2k < n, and the function returns False.
Finally, if n = 2^k with k > 0, then n = 2^k and n - 1 = 2^k - 1 have no bits in common, so n ⊕ (n - 1) = n + (n - 1) > n + 0 = n and the function returns True.

*/

bool
cpe(long n)
{
	return (n ^ (n - 1)) > n;
}

int
main(void)
{
	assert(cpe(2) == true);
	assert(cpe(4) == true);
	assert(cpe(16) == true);
	assert(cpe(128) == true);

	assert(cpe(10) == false);
	assert(cpe(12) == false);
	assert(cpe(14) == false);
	assert(cpe(18) == false);
	assert(cpe(1) == false);

	return 0;
}
