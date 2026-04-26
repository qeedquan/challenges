#include <cassert>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int distance(vector<int> &&streets)
{
	auto size = streets.size();
	if (size == 0)
		return 0;

	sort(streets.begin(), streets.end());

	auto median = streets[size / 2];
	auto result = 0;
	for (auto value : streets)
		result += abs(median - value);
	return result;
}

int main()
{
	assert(distance({ 2, 4 }) == 2);
	assert(distance({ 2, 4, 6 }) == 4);

	return 0;
}
