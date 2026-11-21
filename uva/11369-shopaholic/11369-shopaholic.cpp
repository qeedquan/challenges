#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int solve(vector<int> &&price)
{
	sort(price.rbegin(), price.rend());

	auto total = 0;
	for (size_t i = 2; i < price.size(); i += 3)
		total += price[i];
	return total;
}

int main()
{
	assert(solve({ 400, 100, 200, 350, 300, 250 }) == 400);

	return 0;
}
