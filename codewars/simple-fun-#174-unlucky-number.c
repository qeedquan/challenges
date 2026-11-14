/*

Task
The number is considered to be unlucky if it does not have digits 4 and 7 and is divisible by 13. Please count all unlucky numbers not greater than n.

Example
For n = 20, the result should be 2 (numbers 0 and 13).

For n = 100, the result should be 7 (numbers 0, 13, 26, 39, 52, 65, and 91)

Input/Output
[input] integer n
1 ≤ n ≤ 10^8(10^6 in Python)

[output] an integer

*/

#include <assert.h>
#include <stdio.h>

typedef unsigned long long uvlong;

bool
unlucky(uvlong n)
{
	uvlong m;

	if (n % 13)
		return false;

	for (; n > 0; n /= 10) {
		m = n % 10;
		if (m == 4 || m == 7)
			return false;
	}
	return true;
}

// https://oeis.org/A090620 (related)
uvlong
count(uvlong n)
{
	uvlong c, i;

	for (c = i = 0; i < n; i += 13) {
		if (unlucky(i))
			c++;
	}
	return c;
}

int
main()
{
	assert(count(20) == 2);
	assert(count(100) == 7);
	assert(count(1000) == 40);
	assert(count(1000000) == 20182);

	return 0;
}
