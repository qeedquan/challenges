/*

You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:

    The digit sum of n (the sum of its digits).

    The digit product of n (the product of its digits).

Return true if n is divisible by this sum; otherwise, return false.

Example 1:

Input: n = 99

Output: true

Explanation:

Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.

Example 2:

Input: n = 23

Output: false

Explanation:

Since 23 is not divisible by the sum (2 + 3 = 5) plus product (2 * 3 = 6) of its digits (total 11), the output is false.

Constraints:

    1 <= n <= 10^6

Hint 1
Compute the digits' sum and product, then check if n % (sum + product) == 0.

*/

#include <assert.h>
#include <stdio.h>

#define nelem(x) (sizeof(x) / sizeof(x[0]))

// https://oeis.org/A038366
bool
divisible(int n)
{
	int c, m, p, t;

	if (n < 1)
		return false;

	t = 0;
	p = 1;
	for (c = n; c > 0; c /= 10) {
		t += c % 10;
		p *= c % 10;
	}

	m = t + p;
	if (m == 0)
		return false;
	return n % m == 0;
}

int
main()
{
	static const int tab[] = {
		10, 19, 20, 29, 30, 39, 40, 42, 49, 50, 59, 60, 69, 70, 79, 80, 89, 90,
		99, 100, 102, 108, 110, 120, 126, 132, 140, 150, 180, 190, 200, 201,
		204, 207, 209, 210, 220, 230, 240, 270, 280, 285, 300, 306, 308, 312,
		320, 330, 360, 370, 400, 402, 405, 407, 408, 410
	};

	size_t n;
	int i, j;

	assert(divisible(99) == true);
	assert(divisible(23) == false);

	n = 0;
	j = tab[nelem(tab) - 1];
	for (i = 0; i <= j; i++) {
		if (i == tab[n]) {
			assert(divisible(i) == true);
			n += 1;
		} else {
			assert(divisible(i) == false);
		}
	}

	return 0;
}
