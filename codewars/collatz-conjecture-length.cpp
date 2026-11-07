/*

The Collatz Conjecture states that for any natural number n, if n is even, divide it by 2. If n is odd, multiply it by 3 and add 1. If you repeat the process continuously for n, n will eventually reach 1.

For example, if n = 20, the resulting sequence will be:

[ 20, 10, 5, 16, 8, 4, 2, 1 ]

Write a program that will output the length of the Collatz Conjecture for any given n.
In the example above, the output would be 8.

*/

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

// https://oeis.org/A008908
int collatz(int n)
{
	if (n < 1)
		return 0;

	auto c = 1;
	for (; n > 1; c += 1)
	{
		if (n % 2)
			n = (3 * n) + 1;
		else
			n = n / 2;
	}
	return c;
}

int main()
{
	vector<int> tab =
	{
		1, 2, 8, 3, 6, 9, 17, 4, 20, 7, 15, 10, 10, 18, 18, 5, 13, 21, 21, 8,
		8, 16, 16, 11, 24, 11, 112, 19, 19, 19, 107, 6, 27, 14, 14, 22, 22,
		22, 35, 9, 110, 9, 30, 17, 17, 17, 105, 12, 25, 25, 25, 12, 12, 113,
		113, 20, 33, 20, 33, 20, 20, 108, 108, 7, 28, 28, 28, 15, 15, 15, 103
	};

	for (size_t i = 0; i < tab.size(); i++)
		assert(collatz(i + 1) == tab[i]);

	return 0;
}
