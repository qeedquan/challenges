/*

The simple task
You have to calculate k-th digit of π, knowing that:

π = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342...
Make sure to check the anti-cheat rules at the bottom.

Examples
For k = 0:
3.14159265358979323...
^

For k = 6:
3.14159265358979323...
       ^

Constraints
0 <= k < 10000

Random test cases
1000 tests where 0 <= k < 10000

Anti-cheat

The only import allowed in Python is math
The code length is limited to 2000 characters.
Words http, www, requests, gmpy2 and search are banned.
Eval and exec are banned
Only ASCII characters are allowed

*/

#include <cassert>
#include <iostream>
#include <string>
#include <generator>
#include <boost/multiprecision/gmp.hpp>

using namespace boost::multiprecision;
using namespace std;

generator<mpz_int> genpi()
{
	mpz_int k = 2;
	mpz_int a = 4;
	mpz_int b = 1;
	mpz_int a1 = 12;
	mpz_int b1 = 4;
	for (;;)
	{
		mpz_int p = k * k;
		mpz_int q = (2 * k) + 1;
		k += 1;

		mpz_int xa = a1;
		mpz_int xb = b1;
		mpz_int xa1 = (p * a) + (q * a1);
		mpz_int xb1 = (p * b) + (q * b1);

		a = xa;
		b = xb;
		a1 = xa1;
		b1 = xb1;

		mpz_int d = a / b;
		mpz_int d1 = a1 / b1;
		while (d == d1)
		{
			co_yield d;
			a = 10 * (a % b);
			a1 = 10 * (a1 % b1);
			d = a / b;
			d1 = a1 / b1;
		}
	}
}

int main()
{
	string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342";
	auto generator = genpi();
	auto iterator = generator.begin();
	for (auto value : pi)
	{
		assert(*iterator == value - '0');
		iterator++;
	}

	return 0;
}
