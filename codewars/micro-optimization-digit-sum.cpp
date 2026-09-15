/*

You wrote a program that can calculate the sum of all the digits of a non-negative integer.

However, it's not fast enough. Can you make it faster?

Input size
Python:

50 random tests of n <= 2^64
50 random tests of n <= 2^120000

*/

#include <iostream>
#include <boost/multiprecision/gmp.hpp>

using namespace std;
using namespace boost::multiprecision;

// https://oeis.org/A007953
mpz_int digsum(mpz_int n)
{
	mpz_int r = 0;
	do
	{
		r += n % 10;
		n /= 10;
	} while (n > 0);
	return r;
}

int main()
{
	for (mpz_int i = 0; i < 1000; i++)
		cout << digsum(i) << " ";
	cout << endl;
	return 0;
}
