/*

Return true if n is prime and false if not;

like:
  isPrime(7) == true
  isPrime(-7) == true
  isPrime(6) == false
  isPrime(-6) == false

!important: n always be integer and can be negative (but you need to handle this);

you can't use loops or hardcode (for, while)

*/

#include <stdio.h>
#include <math.h>

bool
recurse(int n, int m)
{
	if (n < 2)
		return false;
	if (m == 1)
		return true;
	if (n % m == 0)
		return false;
	return recurse(n, m - 1);
}

bool
isprime(int n)
{
	if (n < 1)
		return false;
	return recurse(n, sqrt(n));
}

int
main()
{
	int i;

	for (i = -100; i <= 100; i++) {
		if (isprime(i))
			printf("%d\n", i);
	}

	return 0;
}
