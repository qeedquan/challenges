#include <print>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> ages1 = { 3, 4, 2, 1, 5 };
	vector<int> ages2 = { 2, 3, 2, 3, 1 };

	sort(ages1.begin(), ages1.end());
	sort(ages2.begin(), ages2.end());
	
	println("{}", ages1);
	println("{}", ages2);

	return 0;
}
