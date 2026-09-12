#include <cassert>
#include <cstdio>
#include <iostream>

using namespace std;

// https://oeis.org/A008904
int facts(int n)
{
	if (n < 0)
		return 0;

	auto r = 1;
	for (auto i = 2; i <= n; i++)
	{
		r *= i;
		while (!(r % 10))
			r /= 10;
		r %= 100000;
	}
	return r % 10;
}

int main()
{
	static const int tab[] = {
		1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 8, 8, 6, 8, 2, 8, 8, 6,
		8, 2, 4, 4, 8, 4, 6, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2,
		2, 4, 2, 8, 2, 2, 4, 2, 8, 6, 6, 2, 6, 4, 2, 2, 4, 2,
		8, 4, 4, 8, 4, 6, 6, 6, 2, 6, 4, 6, 6, 2, 6, 4, 8, 8,
		6, 8, 2, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2, 2, 2, 4, 2, 8,
		2, 2, 4, 2, 8, 6, 6, 2, 6
	};

	assert(facts(1) == 1);
	assert(facts(2) == 2);
	assert(facts(26) == 4);
	assert(facts(125) == 8);
	assert(facts(3125) == 2);
	assert(facts(9999) == 8);

	for (unsigned i = 0; i < size(tab); i++)
		assert(facts(i) == tab[i]);

	return 0;
}
