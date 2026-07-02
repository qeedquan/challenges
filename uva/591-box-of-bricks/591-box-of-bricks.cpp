#include <cassert>
#include <vector>

using namespace std;

int mean(const vector<int> &a)
{
	auto n = a.size();
	if (n == 0)
		return 0;

	auto r = 0;
	for (auto v : a)
		r += v;
	return r / n;
}

int bricks(const vector<int> &a)
{
	auto m = mean(a);
	auto r = 0;
	for (auto v : a)
	{
		if (v > m)
			r += v - m;
	}
	return r;
}

int main()
{
	assert(bricks({ 5, 2, 4, 1, 7, 5 }) == 5);

	return 0;
}
