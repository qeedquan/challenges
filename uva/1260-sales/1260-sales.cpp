#include <cassert>
#include <set>
#include <vector>

using namespace std;

int solve(const vector<int> &numbers)
{
	multiset<int> prev;
	auto sum = 0;
	for (auto number : numbers)
	{
		auto upper = prev.upper_bound(number);
		sum += distance(prev.begin(), upper);
		prev.insert(number);
	}
	return sum;
}

int main()
{
	assert(solve({ 38, 111, 102, 111, 177 }) == 9);
	assert(solve({ 276, 284, 103, 439, 452, 276, 452, 398 }) == 20);

	return 0;
}
