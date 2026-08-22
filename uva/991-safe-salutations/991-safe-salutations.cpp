#include <cassert>
#include <algorithm>

using namespace std;

long binomial(long n, long k)
{
	if (k < 0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	k = min(k, n - k);

	long c = 1;
	for (long i = 0; i < k; i++)
		c = c * (n - i) / (i + 1);
	return c;
}

// https://oeis.org/A000108
long catalan(long n)
{
	if (n < 0)
		return 0;
	return binomial(2 * n, n) / (n + 1);
}

int main()
{
	assert(catalan(4) == 14);

	return 0;
}
