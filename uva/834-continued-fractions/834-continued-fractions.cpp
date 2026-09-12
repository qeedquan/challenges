#include <print>
#include <vector>

using namespace std;

vector<int> solve(int x, int y)
{
	vector<int> r;
	int t;

	if (y == 0)
		return r;

	while (x % y)
	{
		r.push_back(x / y);
		t = x;
		x = y;
		y = t % y;
	}
	r.push_back(x);

	return r;
}

int main()
{
	println("{}", solve(43, 19));
	println("{}", solve(1, 2));

	return 0;
}
