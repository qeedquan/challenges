#include <cassert>
#include <vector>

using namespace std;

int solve(const vector<int> &numbers)
{
	auto maximum = 0;
	for (auto number : numbers)
		maximum = max(maximum, number);
	return maximum;
}

int main()
{
	assert(solve({ 9, 3, 5, 2, 6 }) == 9);
	assert(solve({ 2 }) == 2);

	return 0;
}
