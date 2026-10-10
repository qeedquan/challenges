#include <cstdio>
#include <algorithm>

using namespace std;

long length(long len, long num)
{
	if (num <= 0)
		return len;
	if ((num == 1) && (len != 0))
		return len;
	if (num % 2)
		return length(len + 1, 3 * num + 1);
	return length(len + 1, num / 2);
}

void range(long a, long b)
{
	long imax = 0;
	long lmax = 0;
	for (auto i = min(a, b); i <= max(a, b); i++)
	{
		auto li = length(0, i);
		if (li > lmax)
		{
			imax = i;
			lmax = li;
		}
	}
	printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",
		   min(a, b), max(a, b), imax, lmax);
}

int main()
{
	range(1, 20);
	range(35, 55);

	return 0;
}
