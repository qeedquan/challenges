/*

Find the number of digits in the factorial of the integer n.
(The factorial of n is the product of all positive integers from 1 to n.)

Input
One integer n (1≤n≤1000000).

Output
Print the number of digits in n!.

Examples
Input #1
7

Answer #1
4

*/

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

// https://oeis.org/A034886
int digfact(int n)
{
	if (n < 0)
		return 0;
	if (n < 2)
		return 1;

	auto ln10 = log(10);
	auto a = log(2 * M_PI * n) / (2 * ln10);
	auto b = (n * log(n / M_E)) / ln10;
	return floor(a + b) + 1;
}

int main()
{
	static const int tab[] = {
		1, 1, 1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 18, 19,
		20, 22, 23, 24, 26, 27, 29, 30, 31, 33, 34, 36, 37, 39, 41, 42, 44, 45,
		47, 48, 50, 52, 53, 55, 57, 58, 60, 62, 63, 65, 67, 68, 70, 72, 74, 75,
		77, 79, 81, 82, 84, 86, 88, 90, 91, 93, 95, 97, 99, 101, 102
	};

	assert(digfact(7) == 4);

	for (size_t i = 0; i < size(tab); i++)
		assert(digfact(i) == tab[i]);

	return 0;
}
