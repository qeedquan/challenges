#include <algorithm>
#include <string>
#include <vector>
#include <print>

using namespace std;

bool compare(const string &string1, const string &string2)
{
	return string2 + string1 < string1 + string2;
}

void solve(vector<string> &&integers)
{
	sort(integers.begin(), integers.end(), compare);
	for (auto integer : integers)
		print("{}", integer);
	println();
}

int main()
{
	solve({ "123", "124", "56", "90" });
	solve({ "123", "124", "56", "90", "9" });
	solve({ "9", "9", "9", "9", "9" });

	return 0;
}
