/*

Comparing two numbers written in index form like 2^11 and 3^7 is not difficult, as any calculator would confirm that 2^11 = 2048 < 3^7 = 2187.

However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.

Your task is to write a function that takes two arrays (or two tuples in Python) in the form of [base, exponent] where base and exponent are positive integers, and return the largest of the two pairs of numbers.

Inspired by Project Euler #99

*/

#include <cassert>
#include <cstdio>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<unsigned long long, unsigned long long> Number;

Number compare(Number x1, Number x2)
{
	if (x1.second * log(x1.first) > x2.second * log(x2.first))
		return x1;
	return x2;
}

int main()
{
	auto x1 = make_pair(632382, 518061);
	auto x2 = make_pair(519432, 525806);

	auto x3 = make_pair(2, 11);
	auto x4 = make_pair(3, 7);

	auto x5 = make_pair(1, 10);
	auto x6 = make_pair(2, 3);

	auto x7 = make_pair(3, 5);
	auto x8 = make_pair(5, 3);

	auto x9 = make_pair(4, 7);
	auto x10 = make_pair(3, 8);

	auto x11 = make_pair(5, 1000);
	auto x12 = make_pair(6, 900);

	auto x13 = make_pair(15991, 714883);
	auto x14 = make_pair(960290, 502358);

	assert(compare(x1, x2) == x1);
	assert(compare(x3, x4) == x4);
	assert(compare(x5, x6) == x6);
	assert(compare(x7, x8) == x7);
	assert(compare(x9, x10) == x9);
	assert(compare(x11, x12) == x12);
	assert(compare(x13, x14) == x14);

	return 0;
}
